//#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
string s;
int next_larger_group[1<<20];

ll solve(bool case2=0){
	CL(next_larger_group,0);
	vector<pii> tmp;
	tmp.pb(pii(-1e9,n));
	int next_zero = n;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='0')next_zero=i;
		else{
			int len = next_zero - i;
			int tmppos = lower_bound(tmp.begin(),tmp.end(),pii(-(len+(case2?0:1)-1),0))-tmp.begin();
			tmppos--;
			next_larger_group[i] = tmp[tmppos].second;
			
			if(i==0 || s[i-1]=='0'){
				int np = i;
				while(np<n && s[np]=='1')np++;
				int g1_len = np - i;
				while(-tmp.back().first<=g1_len)tmp.pop_back();
				tmp.pb(pii(-g1_len, i));
			}
		}
	}
	//REP(i,tmp.size())cout<<tmp[i].first<<' '<<tmp[i].second<<endl;
	vi zp;
	REP(i,n)if(s[i]=='0')zp.pb(i);
	zp.pb(n);
	ll sum = 0;
	int nz=0;
	REP(i,n){
		if(s[i]!='1') continue;
		while(zp[nz]<i)nz++;

		int len = zp[nz] - i;
		sum += ll(1+len)*len/2;

		int nlg = next_larger_group[i];
		int rend = min(n-1, nlg + len - 1 + (case2?-1:0));

		//cout<<case2<<' '<<i<<' '<<rend<<' '<<nlg<<' '<<len<<endl;

		sum += ll(len) * (rend - zp[nz] + 1);
		
		if(i==0) continue;
		if(s[i-1]=='1')continue;
	}
	return sum;
	//cout<<sum<<endl;
}

ll solveall(){
	
	ll t1 = solve();
	reverse(s.begin(),s.end());
	ll t2 = solve(1);
	reverse(s.begin(),s.end());
	
	ll t3 = 0;
	vector<pii> v;
	REP(i,n){
		if(s[i]=='1' && (i==0 || s[i-1]=='0')){
			int np = i;
			while(np<n && s[np]=='1')np++;
			ll len = np - i;
			for(int j=1;j<=len;j++) t3 += ll(j)*(len-j+1);

			v.pb(pii(-len,i));
		}
	}

	ll t4 = 0;
	SORT(v);
	set<pii> sp;
	REP(i,v.size()){
		ll len = -v[i].first;
		set<pii>::iterator it = sp.lower_bound(pii(v[i].second,0));
		int ed = n - 1;
		int bg = 0;

		if(it!=sp.end()){
			ed = (*it).first + len - 1;
		}
		if(it!=sp.begin()){
			--it;
			bg = (*it).first + (*it).second - 1 - len + 2;
		}

		t4 += len * (ed - (v[i].second+len)  + 1) * (v[i].second-1 - bg + 1);

		sp.insert(pii(v[i].second,-v[i].first));
	}

	//cout<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<endl;
	ll res = t1 + t2 - t3 + t4;
	return res;
}


ll stupid(){
	ll res=0;
	for(int l=0;l<s.size();l++){
		int mx=0,c=0;
		for(int i=l;i<s.size();i++){
			if(s[i]=='1'){
				c++;
				mx=max(mx,c);
			}else{
				c=0;
			}
			res+=mx;
		}
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>s;
	cout<<solveall()<<endl;
	return 0;
start:
	n=10;
	s.clear();
	REP(i,n)s.pb("01"[rand()%2]);
	//s="101";
	ll t1 = solveall();
	if(t1==stupid())cout<<"OK "<<t1<<endl;
	else{
		cout<<"FUCK "<<s<<' '<<t1<<' '<<stupid()<<endl;
		return 0;
	}
	goto start;

	cout<<solveall()<<' '<<stupid()<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
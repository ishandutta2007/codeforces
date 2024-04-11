#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
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
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back	

const int mod = 1000000007;
int n,k;
int a[1111111];
int s[1<<21];

void setVal(int pos,int val){
	pos+=(1<<20);
	while(pos){
		s[pos]=max(s[pos],val);
		pos>>=1;
	}
}

int getMax(int p1,int p2){
	p1+=(1<<20);
	p2+=(1<<20);
	int res = 0;
	while(p1<=p2){
		res=max(res,s[p1]);
		res=max(res,s[p2]);
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}
	return res;
}

unordered_map<int,int> ntoid;
vi ps[1<<20];

ll solve(ll from, ll to, ll mx){
	//cout<<"go "<<from<<' '<<to<<' '<<mx<<endl;

	ll res = 0;

	ll len = to-from+1;
	if(k>len) return 0;
	ll cnt = 1 + (len-k)/(k-1);
	res += cnt;

	//cout<<"CNT: "<<cnt<<endl;
	// step 1
	{
		ll to1 = to - k + 1;
		ll from1 = to - (k + (cnt-1)*(k-1)) + 1;
		//[from1,to1] step (k-1)
		if(from1>=mx) res += mx * cnt;
		else if(to1<=mx){
			res += (to1+from1)*cnt/2;
		}else{
			ll stop = (mx - from1)/(k-1);
			res += (from1 + from1 + stop * (k-1)) * (stop+1)/2;
			res += mx * (cnt-stop-1);
		}
	}

	// step 2
	{
		ll from2 = mx - (k+(cnt-1)*(k-1))+1;
		ll to2 = mx-k+1;
		if(from2>=from){
			res -= (from2+to2)*cnt/2;
		}else if(to2<=from){
			res -= from * cnt;
		}else{
			ll first = (from-from2)/(k-1)+1;
			res -= from * first;

			from2 += (k-1)*first;
			cnt -= first;

			res -= (from2+to2)*cnt/2;
		}
	}

	return res%mod;
}

ll z(vi a, int k){
	if(a.size()<k) return 0;
	vi b;
	ll ans = 0;
	REP(i,a.size()-k+1){
		ll tmp = a[i];
		REP(j,k)tmp=max(tmp,(ll)a[j+i]);
		b.pb(tmp);
		ans+=tmp;
	}
	return ans + z(b,k);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

start:
	//n=10;k=3;REP(i,n)a[i]=rand()%5; /* a[0]=0;a[1]=0;a[2]=a[3]=1; */// cout<<n<<' '<<k<<endl;REP(i,n)cout<<a[i]<<' ';puts("");
	

	cin>>n>>k;REP(i,n)scanf("%d",a+i);
	CL(s,0);
	REP(i,ntoid.size()) ps[i].clear();
	ntoid.clear();
	
	vi tmp;
	REP(i,n)setVal(i,a[i]),tmp.pb(a[i]);
	UN(tmp);
	REP(i,tmp.size()){
		ntoid[tmp[i]]=i;
	}
	REP(i,n)ps[ntoid[a[i]]].pb(i);
	queue<pii> q;
	q.push(pii(0,n-1));
	ll res = 0;
	while(!q.empty()){
		int from = q.front().first;
		int to = q.front().second;
		q.pop();
		int num = to-from+1;
		if(num<k) continue;

		int mx = getMax(from,to);
		vi& pos = ps[ntoid[mx]];
		int val = *lower_bound(pos.begin(),pos.end(),from);
		if(a[val]){
			ll rr = solve(from,to,val);
			//cout<<a[val]<<' '<<rr<<endl;
			res = (res + a[val] * rr) % mod;
		}

		q.push(pii(from,val-1));
		q.push(pii(val+1,to));
	}
	/*vi aa;
	REP(i,n)aa.pb(a[i]);
	if(res == z(aa,k)) {cout<<"OK "<<res<<endl;goto start;}
	cout<<res<<' '<<z(aa,k)<<endl;
	*/
	cout<<res<<endl;
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
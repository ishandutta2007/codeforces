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
int a[111111];
int c[111111];

int solve(vector<pii> v){
	vector<pii> v2;
	map<int,int> v1;
	REP(i,v.size()){
		if(v[i].first==v[i].second)v1[v[i].first]++;
		else v2.pb(v[i]);
	}
	int res=0;
	priority_queue<pii> q;
	for(map<int,int>::iterator it = v1.begin();it!=v1.end();it++)q.push(pii(it->second,it->first));
	int dcnt=0;
	int dcol=0;
	while(!q.empty()){
		pii c = q.top();q.pop();
		if(!q.empty()){
			pii z = q.top();q.pop();
			v2.pb(pii(c.second,z.second));
			z.first--;
			if(z.first>0)q.push(z);
			c.first--;
			if(c.first>0)q.push(c);
			res++;
		}else{
			dcnt=c.first;
			dcol=c.second;
			break;
		}
	}
	REP(i,v2.size()){
		if(dcnt>0){
			if(v2[i].first==dcol || v2[i].second==dcol){
				
			}else{
				dcnt--;
				res++;
			}
		}
	}
	
	int v2s = v2.size();
	
	if(v2s>0){
		res += v2s - 1;
	}
	if(dcnt>0){
		res += (dcnt -1)*2;
	}
	if(v2.size()>0 && dcnt>0)res++;

	//cout<<"?"<<v2.size()<<' '<<dcnt<<endl;
	return res;
}

int p[111];
int stupid(){
	int best=-1;
	REP(i,n)p[i]=i;
	do{
		bool g=1;
		int r=0;
		FOR(i,1,n){
			if(a[p[i]]==a[p[i-1]]){g=0;break;}
			if(abs(p[i]-p[i-1])>1)r++;
		}
		if(g){
			if(best==-1 || best>r)best=r;
		}
	}while(next_permutation(p,p+n));
	return best;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)scanf("%d",a+i);

		//start:
		//n=rand()%8+1;
		//REP(i,n)a[i]=rand()%n+1;
	
		REP(i,n+1)c[i]=0;
		REP(i,n)c[a[i]]++;
		int mx = 0;
		REP(i,n+1)mx=max(mx,c[i]);
		int res=-1;
		if(mx+mx-1>n)res=-1;
		else{
			int pos = 0;
			vector<pii> v;
			REP(i,n){
				if(i+1==n || a[i]==a[i+1]){
					v.pb(pii(a[pos],a[i]));
					pos=i+1;
				}
			}
			res=solve(v);
		}
		/*int sr = stupid();
		/cout<<res<<' '<<sr<<endl;
		if(res==sr)goto start;
		else{
			cout<<n<<endl;
			REP(i,n)cout<<a[i]<<' ';puts("");
			puts("FOUND");
			break;
		}*/
		cout<<res<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
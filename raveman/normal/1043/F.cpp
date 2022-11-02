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

int n;
int a[333333];

int p[333333];

int m[333333];
int g[333333];
int r[333333];


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	for(int i=2;i<333333;i++){
		if(p[i]) continue;
		for(ll j=ll(i)*i;j<333333;j+=i){
			p[j]=i;
		}
	}

	cin>>n;
	REP(i,n)scanf("%d",a+i);

	CL(r,-1);
	queue<int> q;

	REP(i,n){
		vi pr;
		while(p[a[i]]){
			int div = p[a[i]];
			pr.pb(div);
			while(a[i]%div==0)a[i]/=div;
		}
		if(a[i]>1) pr.pb(a[i]);

		int z = 1;
		REP(j,pr.size()) z*=pr[j];
		if(r[z]==-1){
			r[z]=1;
			q.push(z);
		}

		REP(j,1<<pr.size()){
			int t = 1;
			REP(k,pr.size())if(j&(1<<k))t*=pr[k];
			m[t]++;
		}
	}


	FOR(jj,1,333333){
		int tc = jj;
		vi pr;
		while(p[tc]){
			int div = p[tc];
			pr.pb(div);
			while(tc%div==0)tc/=div;
		}
		if(tc>1) pr.pb(tc);

		FOR(j,1,1<<pr.size()){
			int t = 1,nm=0;
			REP(k,pr.size())if(j&(1<<k))t*=pr[k],nm++;
			if(nm%2==0){
				g[jj] -= m[t];
			}else{
				g[jj] += m[t];
			}
		}
		//if(g[jj])cout<<jj<<' '<<g[jj]<<endl;
	}

	while(!q.empty()){
		if(r[1]!=-1)break;

		int c = q.front();
		q.pop();


		int tc = c;
		vi pr;
		while(p[tc]){
			int div = p[tc];
			pr.pb(div);
			while(tc%div==0)tc/=div;
		}
		if(tc>1) pr.pb(tc);

		REP(j,1<<pr.size()){
			int t = 1;
			REP(k,pr.size())if(j&(1<<k))t*=pr[k];
			if(g[t]!=n){
				int nc = c / t;
				if(r[nc]==-1){
					r[nc]=r[c]+1;
					q.push(nc);
				}
			}
		}
	}

	cout<<r[1]<<endl;



	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
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

bool isP(int p){
	for(int i=2;i*i<=p;i++)if(p%i==0) return 0;
	return 1;
}

vi m;

void generate(vi& p,int pos,int to, int limit,ll curr=1){
	if(pos==to) m.pb(curr);
	else{
		while(curr<=limit){
			generate(p,pos+1,to,limit,curr);
			curr*=p[pos];
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int k;
	cin>>k;
	vi p;
	for(int i=2;i<=100;i++){
		bool pr = 1;
		for(int j=2;j*j<=i;j++)if(i%j==0)pr=0;
		if(pr)p.pb(i);
	}
	vi res;
	FOR(pr,1,p.size()){
		if(pr==p.size()-1) puts("FUCK");
		m.clear();
		generate(p,0,pr,k*k*2);
		//cout<<m.size()<<endl;
		vi need(pr);
		REP(i,pr) need[i]=(k+1)/2;
		SORT(m);res.clear();
		for(int i=pr;i>=1;i--){
			REP(j,m.size()){
				int cover = 0;
				REP(k,pr) if(m[j]%p[k]==0 && need[k]>0)cover++;
			//	cout<<cover<< ' '<<m[j]<<' '<<need[0]<<endl;
				if(cover==i){
					res.pb(m[j]);					
					REP(k,pr) if(m[j]%p[k]==0 && need[k]>0)need[k]--;
					m[j]=1;
				}
			}
		}
		if(need==vi(pr,0)){
			if(res.size() > k) continue;
			res.pb(1);
			REP(i,m.size()) if(m[i]!=1 && res.size()<k) res.pb(m[i]);
			if(res.size() < k) continue;
			break;
		}
	}
	REP(i,res.size()){
		if(i)printf(" ");
		cout<<res[i];
	}
	puts("");
	//cout<<k*k*2<<endl;
	

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
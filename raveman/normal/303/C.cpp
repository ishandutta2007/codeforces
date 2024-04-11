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

int n,k;
int a[5555];

int s[1111111];
vi ss[1111111];
int p[1111111];
int d[1111111];
int r[1111111];
bool SHIT;

int pr[22];
int pw[22];
int num,I,J,CNT;
vi V;
void dfs(int pos,int c){
	if(s[c]>10) return;
	if(pos==num){
		s[c]+=CNT;
		if(SHIT) s[c]=11;
		if(s[c]<=10){
			REP(i,V.size()) ss[c].pb(V[i]);
		}
	}else{
		REP(i,pw[pos]+1){
			dfs(pos+1,c);
			c/=pr[pos];
		}
	}
}
void add(int diff){
	if(s[diff]>10) return;
	num=0;
	int x = diff;
	while(diff>1){
		if(p[diff]==0){
			pr[num]=diff;
			pw[num]=1;
			diff=1;
		}else{
			pr[num]=p[diff];
			pw[num]=r[diff];
			diff=d[diff];
		}
		num++;
	}
	dfs(0,x);
}

int now = 0;
int u[1111111];
int u2[1111111];

int zz[1111111];
vi  ZZ[1111111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	for(int i=2;i<1111111;i++)if(p[i]==0)for(int j=i+i;j<1111111;j+=i)p[j]=i;
	for(int i=2;i<1111111;i++)if(p[i]){
		int t = i;
		int c = 0;
		while(t%p[i]==0) t/=p[i],c++;
		d[i]=t;
		r[i]=c;
	}
	cin>>n>>k;
	//n=5000;k=4;
	//REP(i,n)a[i]=rand()%1000000*0-i*2+1000000;//+1+1000000;
	REP(i,n)cin>>a[i];
	sort(a,a+n);
	REP(i,n)REP(j,i){
		int diff = a[i]-a[j];
		zz[diff]++;
	}
	SHIT=1;
	for(int i=0;i<1111111;i++)if(zz[i]>10)add(i);
	SHIT=0;
	REP(i,n)REP(j,i)if(zz[a[i]-a[j]]<=10){
		ZZ[a[i]-a[j]].pb(i);
		ZZ[a[i]-a[j]].pb(j);
	}
	REP(i,1111111)if(!ZZ[i].empty()) UN(ZZ[i]);
	for(int i=0;i<1111111;i++)if(zz[i]>0 && zz[i]<=10){CNT=zz[i];V=ZZ[i];add(i);}
	for(int m=1;m<=1000001;m++)if(s[m]<=10){
		now++;
		int need=0;
		REP(i,ss[m].size()){
			if(u2[ss[m][i]]==now) continue;
			u2[ss[m][i]]=now;
			int w = a[ss[m][i]]%m;
			if(u[w]!=now)u[w]=now;
			else need++;
		}
		if(k>=need){
			cout<<m<<endl;
			break;
		}
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
#pragma comment(linker, "/STACK:60777216")  

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

int n;
int a[222222];

bool u[2][222222];
bool v[2][222222];
ll   r[2][222222];

ll go(int x,int st=0){
	if(x<=0 || x>n) return 0;
	if(x==1) return (go(x+a[x],1)==-1 ? -1 : go(x+a[x],1)+a[x]);
	else{
		if(u[st][x] && !v[st][x]) return -1;
		if(u[st][x] &&  v[st][x]) return r[st][x];

		u[st][x]=true;
		int nx = x + (st==0?a[x]:-a[x]);
		if(nx==1){
			v[st][x]=true;
			return r[st][x]=-1;
		}
		ll t = go(nx,st^1);
		v[st][x]=true;
		if(t==-1) return r[st][x]=-1;
		return r[st][x] = t+a[x];
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n-1) scanf("%d",a+i+2);
	FOR(i,1,n){
		a[1]=i;
		cout<<go(1)<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
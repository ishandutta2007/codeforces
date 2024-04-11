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
int a[22][22];
int b[22][22];
int c[22][22];

int w[22][22];
int mw[22],wm[22];
int rr[22],cc[22];
bool u[22],U[22];
bool dfs(int v){
    if(v<0) return true;
    if(u[v]) return false;
    u[v]=true;
    if(mw[v]!=-1)U[mw[v]]=true;
    REP(i,n) if(!w[v][i] && dfs(wm[i]))
        return mw[v]=i,wm[i]=v,true;
    return false;
}

bool iteration(){	
	int maxp=0;
    REP(i,n) if(mw[i]!=-1 || (CL(u,false),dfs(i))) maxp++;
    if(maxp==n) return true;
    int mn=1e9;
    CL(u,false),CL(U,false);
    REP(i,n) if(mw[i]==-1) dfs(i);
    REP(i,n) if(u[i]) REP(j,n) if(!U[j]) mn=min(mn,w[i][j]);
	REP(i,n)if(u[i])rr[i]-=mn;
	REP(j,n)if(U[j])cc[j]+=mn;
    REP(i,n)if(u[i])REP(j,n)w[i][j]-=mn;
	REP(j,n)if(U[j])REP(i,n)w[i][j]+=mn;
	return false;
}

void egervary(){
	memcpy(w,c,sizeof c);
	CL(mw,-1),CL(wm,-1);	
    while(!iteration());
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)REP(j,n)scanf("%d",&a[i][j]);
	REP(i,n)REP(j,n)scanf("%d",&b[i][j]);

	vi tt;
	REP(i,1<<n){
		int nb=0;
		REP(j,n)if(i&(1<<j))nb++;
		if(nb==n/2) tt.pb(i);
	}

	int res=0;
	REP(mask_index,tt.size()){
		int mask = tt[mask_index];		
		if(mask_index==0){
			REP(i,n)REP(j,n)c[i][j]=1000000-((mask&(1<<j))?b[i][j]:a[i][j]);
			egervary();
		}else{
			int prev_mask = tt[mask_index-1];
			int diff = prev_mask^mask;
			REP(j,n)if(diff&(1<<j)){
				mw[wm[j]]=-1;
				wm[j]=-1;
				int mn=1e9;
				REP(i,n){
					c[i][j]=1000000-((mask&(1<<j))?b[i][j]:a[i][j]);
					w[i][j]=c[i][j]+rr[i];
					mn=min(mn,w[i][j]);
				}
				REP(i,n)w[i][j]-=mn;
			}
			while(!iteration());
		}
		int cost = 0;
		REP(i,n)cost+=1000000-c[i][mw[i]];
		res=max(res,cost);
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}
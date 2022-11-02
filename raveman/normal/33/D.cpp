#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n,m,k;
int kx[1111],ky[1111];
int r[1111],x[1111],y[1111];
int d[1111][1111];
int f[1111];
vi v[1111];

bool u[1111];

void dfs(int ver,int start,int dd=0){
	if(u[ver]) return;
	u[ver]=true;
	d[start][ver] = dd;
	REP(i,v[ver].size())
		dfs(v[ver][i],start,dd+1);
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	cin>>n>>m>>k;
	REP(i,n) scanf("%d %d",kx+i,ky+i);
	REP(i,m) scanf("%d %d %d",r+i,x+i,y+i);

	REP(i,n){
		int pos = -1;

		REP(j,m)if(ll(kx[i]-x[j])*(kx[i]-x[j])+ll(ky[i]-y[j])*(ky[i]-y[j])<=ll(r[j])*r[j])
			if(pos==-1 || r[j]<r[pos])
				pos=j;

		if(pos==-1) pos=m;
		f[i]=pos;
	}

	REP(i,m){
		int pos = -1;

		REP(j,m)if(r[j]>r[i]){
			if(ll(x[i]-x[j])*(x[i]-x[j])+ll(y[i]-y[j])*(y[i]-y[j])<=ll(r[j])*r[j]){
				if(pos==-1 || r[j]<r[pos])
					pos=j;
			}
		}

		if(pos==-1) pos = m;

		v[i].pb(pos);
		v[pos].pb(i);
	}

	REP(i,m+1){
		CL(u,false);
		dfs(i,i);
	}

	REP(i,k){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		x=f[x],y=f[y];
		printf("%d\n",d[x][y]);
	}

	return 0;
}
#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n;
int x[5555];
int y[5555];

vi v[5555];

const int mod = 1000000007;
int c[5555];
int comp[5555];
int numv[5555];

void repaint(int ver,int col,int cmp){
	if(comp[ver]==cmp) return;
	comp[ver]=cmp;
	c[ver]=col;
	REP(i,v[ver].size())
		repaint(v[ver][i],1-col,cmp);
}

bool dfs(int ver,int col=0){
	if(c[ver]!=-1) return c[ver]==col;
	c[ver]=col;
	REP(i,v[ver].size())
		if(!dfs(v[ver][i],1-col))
			return 0;
	return 1;
}

pii solve(int r){
	REP(i,n) v[i].clear(),c[i]=-1;
	REP(i,n)REP(j,i){
		int d = abs(x[i]-x[j])+abs(y[i]-y[j]);
		if(d>r) v[i].pb(j),v[j].pb(i);
	}
	int num = 1;
	REP(i,n)if(c[i]==-1){
		if(!dfs(i)) return pii(-1,-1);
		num += num;
		if(num >= mod) num -=mod;
	}
	return pii(r,num);

}

vector<pii> d[10001];

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d %d",x+i,y+i),comp[i]=i,c[i]=0,numv[i]=1;
	REP(i,n)REP(j,i)d[abs(x[i]-x[j])+abs(y[i]-y[j])].pb(pii(i,j));
	int numc = n;
	pii res(10000,numc);
	for(int dist =  9999;dist>=0;dist--){
		bool good = 1;
		REP(i,d[dist+1].size()){
			int v1 = d[dist+1][i].first;
			int v2 = d[dist+1][i].second;
			if(comp[v1]==comp[v2]){
				if(c[v1]==c[v2]){
					good=0;
					break;
				}
			}else{
				numc--;
				
				if(numv[comp[v1]] >= numv[comp[v2]]){
					numv[comp[v1]] += numv[comp[v2]];
					repaint(v2,1-c[v1],comp[v1]);
				}else{
					numv[comp[v2]] += numv[comp[v1]];				
					repaint(v1,1-c[v2],comp[v2]);
				}

				v[v1].pb(v2);
				v[v2].pb(v1);
			}
		}
		if(!good) break;
		res.first = dist;
		res.second = numc;
	}
	int rr = 1;
	while(res.second){
		rr += rr;
		if(rr>=mod) rr-=mod;
		res.second--;
	}
	cout<<res.first<<endl<<rr<<endl;
	return 0;
}
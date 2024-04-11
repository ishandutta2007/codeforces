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
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n,m;
vector<pii> v[11111];
int u[11111];
int num_bad;
int c[11111];
int nb[11111];
int ng[11111];
int last_ind;

void dfs(int ver,int par=-1,int d=0){
	c[ver]=d;u[ver]=1;
	REP(i,v[ver].size()){
		int nv = v[ver][i].first;
		if(nv==par)continue;

		if(!u[nv]){
			dfs(nv,ver,d+1);
			nb[ver]+=nb[nv];
			ng[ver]+=ng[nv];
		}else{
			if(u[nv]==1){
				if((c[ver]%2)==(c[nv]%2)){
					nb[ver]++;
					num_bad++;
					last_ind = v[ver][i].second;
				}else{
					ng[ver]++;
				}
			}else{
				if((c[ver]%2)==(c[nv]%2)){
					nb[ver]--;
				}else{
					ng[ver]--;
				}
			}
		}
	}
	u[ver]=2;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(pii(y,i));
		v[y].pb(pii(x,i));
	}

	REP(i,n)if(!u[i])
		dfs(i);

	if(num_bad==0){
		cout<<m<<endl;
		REP(i,m){
			if(i)printf(" ");
			printf("%d",i+1);
		}
		puts("");
	}else{
		vi r;
		if(num_bad==1) r.pb(last_ind+1);

		REP(i,n)REP(j,v[i].size()){
			int nv = v[i][j].first;
			if(c[nv] == c[i]+1){
				if(nb[nv] == num_bad && ng[nv]==0)
					r.pb(v[i][j].second+1);
			}
		}
		SORT(r);
		cout<<r.size()<<endl;
		REP(i,r.size()){
			if(i) printf(" ");
			printf("%d",r[i]);
		}
		puts("");
	}
	
	return 0;
}
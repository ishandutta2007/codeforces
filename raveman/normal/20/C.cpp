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
vector<pii> v[111111];
ll d[111111];
int f[111111];

priority_queue<pair<ll,int> > q;

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		v[x].pb(pii(y,z));
		v[y].pb(pii(x,z));
	}
	REP(i,n+1) d[i]=-1;
	d[1]=0;
	q.push(pair<ll,int>(0,1));
	while(!q.empty()){
		pair<ll,int> curr = q.top();
		q.pop();

		int ver = curr.second;
		ll cost = -curr.first;
		if(d[ver]!=cost)continue;

		REP(i,v[ver].size()){
			int nv = v[ver][i].first;
			ll nc = cost + v[ver][i].second;
			if(d[nv]==-1 || d[nv]>nc)
				q.push(pair<ll,int>(-nc,nv)),d[nv]=nc,f[nv]=ver;
		}
	}
	if(d[n]==-1) puts("-1");
	else{
		vi v;
		int curr = n;
		while(curr!=1){
			v.pb(curr);
			curr=f[curr];
		}
		v.pb(1);
		REP(i,v.size()){
			if(i) printf(" ");
			printf("%d",v[v.size()-1-i]);
		}
		puts("");
	}
	return 0;
}
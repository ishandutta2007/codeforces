#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

int n,m;
vector<pii> v[111111];
int k;
bool p[111111];

typedef pair<ll,ll> pl;
ll d[111111];

ll solve(){
	CL(d,-1);
	d[0]=0;
	priority_queue<pl> q;
	q.push(pl(0,0));
	while(!q.empty()){
		int curr = q.top().second;
		ll cost = -q.top().first;
		q.pop();
		if(p[curr]) return cost;
		if(d[curr]!=cost) continue;
		REP(i,v[curr].size()){
			ll nc = cost + v[curr][i].second;
			int nw = v[curr][i].first;
			if(d[nw]==-1 || d[nw]>nc){
				d[nw]=nc;
				q.push(pl(-nc,nw));
			}
		}
	}
}
bool vv[111111];
ll solve2(){
	int start = -1;
	REP(i,n)if(p[i]) start=i;

	ll res = 0;
	CL(d,-1);
	d[start]=0;
	priority_queue<pl> q;
	q.push(pl(0,start));
	while(!q.empty()){
		int curr = q.top().second;
		ll cost = -q.top().first;
		q.pop();
		if(d[curr]>cost) continue;
		if(p[curr] && !vv[curr]){
			vv[curr]=1;
			res += cost;
			d[curr]=0;
			q.push(pl(0,curr));
			//cout<<"here "<<curr<<' '<<cost<<endl;
		}
		REP(i,v[curr].size()){
			ll nc = cost + v[curr][i].second;
			int nw = v[curr][i].first;
			if(d[nw]==-1 || d[nw]>nc){
				d[nw]=nc;
				q.push(pl(-nc,nw));
			}
		}
	}
	return res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		x--,y--;
		v[x].pb(pii(y,z));
		v[y].pb(pii(x,z));
	}
	int k;
	cin>>k;
	REP(i,k){
		int x;
		scanf("%d",&x);
		x--;
		p[x]=1;
	}

	cout<<solve()+solve2()<<endl;
	
#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}
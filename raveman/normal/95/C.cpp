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

int n,m;
int x,y;
vector<pii> v[1111];
int t[1111],c[1111];
ll  d[1111];
ll  D[1111];
bool u[1111];

priority_queue< pair<ll,int> > pq;

void dj(int ver){
	CL(D,-1);
	int curr = ver;
	D[curr] = 0;
	pq.push(make_pair(0ll,curr));
	while(!pq.empty()){
		ll cost = -pq.top().first;
		int ver = pq.top().second;
		pq.pop();

		if(D[ver]!=cost) continue;
		REP(i,v[ver].size()){
			int nw = v[ver][i].first;
			ll ncost = cost + v[ver][i].second;
			if(D[nw]==-1 || D[nw] > ncost){
				D[nw] = ncost;
				pq.push(make_pair(-ncost,nw));
			}
		}
	}
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>x>>y;x--,y--;
	REP(i,m){
		int _x,_y,_z;
		cin>>_x>>_y>>_z;
		_x--,_y--;
		v[_x].pb(pii(_y,_z));
		v[_y].pb(pii(_x,_z));
	}
	REP(i,n) cin>>t[i]>>c[i];
	CL(d,-1);
	d[x] = 0;

	int curr = x;

	while(1){
		u[curr] = true;

		dj(curr);
		REP(i,n) if(D[i]!=-1 && D[i]<=t[curr] && (d[i]==-1 || d[i]>d[curr]+c[curr]))
			d[i] = d[curr] + c[curr];
		int mx = -1;
		REP(i,n) if(!u[i] && d[i]!=-1 && (mx==-1 || d[i]<d[mx])) mx = i;
		if(mx==-1) break;
		curr = mx;
		//cout<<curr<<' '<<d[curr]<<endl;
	}

	cout<<d[y]<<endl;
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}
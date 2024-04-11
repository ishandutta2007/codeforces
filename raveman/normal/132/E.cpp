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

int nb(int x){return x==0?0:1+nb(x&(x-1));}

int n,m;
int a[555];

vector<pii> v[666];

const int inf = 1011111111;

int d[666];
int f[666];

int flow(){
	int N = 2*n+m+2;
	REP(i,N) d[i] = inf;
	int start = N - 2;

	d[start] = 0;
	priority_queue<pii> q;
	q.push(pii(0, start));

	while(!q.empty()){
		pii curr = q.top();q.pop();
		int ver = curr.second;
		int cost = -curr.first;
		if(d[ver]<cost) continue;

		REP(i,v[ver].size()){

			int nw = v[ver][i].first;
			int ncost = cost + v[ver][i].second;

			if(d[nw] > ncost){
				d[nw] = ncost;
				f[nw] = ver;
				q.push(pii(-ncost, nw));
			}
		}
	}

	int curr = N-1;
	while(curr!=N-2){
		int prev = f[curr];

		bool found = false;
		REP(i,v[prev].size()) if(v[prev][i].first == curr){
			swap(v[prev][i], v[prev].back());
			int cost = v[prev].back().second;
			v[prev].pop_back();

			v[curr].pb(pii(prev, -cost));

			found = true;
			break;
		}
		if(!found) puts("FACK");
		curr = prev;
	}

	
	return d[N-1];
}

string conv(int a){
	stringstream ss;
	ss<<a;
	return ss.str();
}

string var[333];

int main(){
#ifdef LocalHost

    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) cin>>a[i];
	REP(i,n) FOR(j,i+1,n) if(a[i]==a[j]) v[i].pb(pii(n+m+j,0));
	else v[i].pb(pii(n+m+j,nb(a[j])));
	REP(i,m)REP(j,n) v[n+i].pb(pii(n+m+j,nb(a[j])));
	REP(i,n+m) v[2*n+m].pb(pii(i,0));
	REP(i,n) v[n+m+i].pb(pii(2*n+m+1,0));

	if(0)REP(i,2*n+m+2){
		cout<<"ver "<<i<<": ";
		REP(j,v[i].size())
			cout<<v[i][j].first<<','<<v[i][j].second<<" ";
		puts("");
		//	cout<<v[n+m+i].size()<<endl;
		//res.pb("print("+a+")");
	}

	int cost = 0;
	REP(tt,n) cost += flow();
	vector<string> res;

	REP(i,n){
		//cout<<"ver "<<i<<": ";
		//REP(j,v[n+m+i].size())
		//	cout<<v[n+m+i][j].first<<','<<v[n+m+i][j].second<<" ";
		//puts("");
		//cout<<v[n+m+i].size()<<endl;
		int from = v[n+m+i][0].first;
		if(from>=n){
			var[i] = string(1,char('a'+from-n));
			res.pb(var[i]+"="+conv(a[i]));
		}else{
			var[i] = var[from];
			if(a[i]!=a[from]) res.pb(var[i]+"="+conv(a[i]));
		}
		res.pb("print("+var[i]+")");

	}

	cout<<res.size()<<' '<<cost<<endl;
	REP(i,res.size()) cout<<res[i]<<endl;


#ifdef LocalHost
    cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}
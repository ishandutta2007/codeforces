
// Problem : C. Array and Operations
// Contest : Codeforces Round #284 (Div. 1)
// URL : https://codeforces.com/contest/498/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=100,L=30,source=N*L+1,sink=N*L+2;
struct edge{
	int nxt,flow,rev;
};
vector<vector<edge> > graf(N*L+3);
void addEdge(int a,int b){
	edge aa={b,0,graf[b].size()},bb={a,1,graf[a].size()};
	graf[a].pb(aa);
	graf[b].pb(bb);
}
vector<int> factor(int a){
	vector<int> factors;
	for(int i=2;i*i<=a;i++){
		while(a%i==0)
			factors.pb(i),a/=i;
	}
	if(a!=1)
		factors.pb(a);
	return factors;
}
vector<int> level(N*L+3),st(N*L+3);
bool bfs(){
	fill(all(level),-1);
	fill(all(st),0);
	queue<int> q;
	q.push(source);
	level[source]=0;
	while(q.size()){
		int tr=q.front();
		q.pop();
		for(auto p:graf[tr])
			if(level[p.nxt]==-1&&p.flow==0)
				level[p.nxt]=level[tr]+1,q.push(p.nxt);
	}
	return level[sink]!=-1;
}
int dfs(int tr){
	if(tr==sink)
		return 1;
	for(;st[tr]<(int)graf[tr].size();st[tr]++){
		auto p=graf[tr][st[tr]];
		if(p.flow==0&&level[p.nxt]==level[tr]+1){
			if(dfs(p.nxt)){
				graf[p.nxt][p.rev].flow^=1;
				graf[tr][st[tr]].flow^=1;
				return 1;
			}
		}
	}
	return 0;
}
int dinic(){
	int flw=0;
	while(bfs())
		while(dfs(source))
			flw++;
	return flw;
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	vector<int> a(n);
	vector<vector<int> > factors(n);
	for(int i=0;i<n;i++)
		scanf("%i",&a[i]),factors[i]=factor(a[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<(int)factors[i].size();j++)
			if(i&1)
				addEdge(i*L+j,sink);
			else
				addEdge(source,i*L+j);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		if(a&1)
			swap(a,b);
		for(int x=0;x<factors[a].size();x++)
			for(int y=0;y<factors[b].size();y++)
				if(factors[a][x]==factors[b][y])
					addEdge(a*L+x,b*L+y);
	}
	//return 0;
	printf("%i\n",dinic());
	return 0;
}

// Problem : F. Simple Cycles Edges
// Contest : Educational Codeforces Round 42 (Rated for Div. 2)
// URL : https://codeforces.com/contest/962/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
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

const int N=1e5+5;
vector<vector<int> > graf(N);
vector<int> in(N),lo(N);
map<pair<int,int>,int> edgeId;
int t=1;
vector<pair<int,int> > edgeStk;
vector<vector<pair<int,int> > > components;
void dfs(int tr,int par){
	in[tr]=lo[tr]=t++;
	int cnt=tr!=par;
	for(auto p:graf[tr]){
		if(p==par)
			continue;
		if(!in[p]){
			edgeStk.pb({tr,p});
			dfs(p,tr);
			lo[tr]=min(lo[tr],lo[p]);
			if(lo[p]>=in[tr])
				cnt++;
			if(cnt>1&&lo[p]>=in[tr]){
				vector<pair<int,int> > ok;
				while(edgeStk.back()!=make_pair(tr,p))
					ok.pb(edgeStk.back()),edgeStk.pop_back();
				ok.pb(edgeStk.back()),edgeStk.pop_back();
				components.pb(ok);
			}
		}
		else{
			lo[tr]=min(lo[tr],in[p]);
			if(in[p]<in[tr])
				edgeStk.pb({p,tr});
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		edgeId[{a,b}]=edgeId[{b,a}]=i+1;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	for(int i=0;i<n;i++)
		if(!in[i]){
			dfs(i,i);
			if(edgeStk.size())
				components.pb(edgeStk),edgeStk.clear();
		}
	vector<int> sol;
	for(auto p:components){
		map<int,int> cnt;
		for(auto d:p)
			cnt[d.f]++,cnt[d.s]++;
		bool sve=1;
		for(auto d:cnt)
			if(d.s!=2)
				sve=0;
		if(sve)
			for(auto d:p)
				sol.pb(edgeId[d]);
	}
	sort(all(sol));
	printf("%i\n",sol.size());
	for(auto p:sol)
		printf("%i ",p);
	return 0;
}
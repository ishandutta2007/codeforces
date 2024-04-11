
// Problem : F. Berland Beauty
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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

const int N=5001;
vector<vector<int> > graf(N);
vector<int> par(N),dep(N),sol(N,1),ed(N);
map<pair<int,int>,int> sc;
void dfs(int tr,int pa){
	for(auto p:graf[tr])
		if(p!=pa)
			par[p]=tr,dep[p]=dep[tr]+1,dfs(p,tr);
}
void update(int a,int b,int x){
	bool stavio=0;
	while(a!=b){
		if(dep[a]>=dep[b]){
			if(sol[ed[a]]==1||sol[ed[a]]==x)
				sol[ed[a]]=x,stavio=1;
			a=par[a];
		}
		else{
			if(sol[ed[b]]==1||sol[ed[b]]==x)
				sol[ed[b]]=x,stavio=1;
			b=par[b];
		}
	}
	if(!stavio){
		printf("-1\n");
		exit(0);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,a,b;
	scanf("%i",&n);
	for(int i=1;i<n;i++)
		scanf("%i %i",&a,&b),a--,b--,sc[{a,b}]=sc[{b,a}]=i-1,graf[a].pb(b),graf[b].pb(a);
	int q;
	scanf("%i",&q);
	vector<pair<int,pair<int,int> > > qq;
	while(q--){
		int a,b,g;
		scanf("%i %i %i",&a,&b,&g);
		a--;b--;
		qq.pb({g,{a,b}});
	}
	dfs(0,0);
	for(int i=1;i<n;i++)
		ed[i]=sc[{i,par[i]}];
	sort(qq.rbegin(),qq.rend());
	for(auto p:qq)
		update(p.s.f,p.s.s,p.f);
	for(int i=0;i<n-1;i++)
		printf("%i ",sol[i]);
	return 0;
}

// Problem : F. Ehab's Last Theorem
// Contest : Codeforces Round #628 (Div. 2)
// URL : https://codeforces.com/contest/1325/problem/F
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
#define sz(x) (int)(x).size()
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

const int N=1e5+5;
vector<vector<int> > graf(N);
vector<int> par(N),dep(N,-1);
vector<vector<int> > deps(N);
int treba;
void dfs(int tr){
	deps[dep[tr]%(treba-1)].pb(tr);
	for(auto p:graf[tr])
		if(dep[p]==-1)
			dep[p]=dep[tr]+1,par[p]=tr,dfs(p);
}

int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	vector<pair<int,int> > edges;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		graf[a].pb(b);
		graf[b].pb(a);
		edges.pb({a,b});
	}
	treba=ceil(sqrt(n));
	dep[0]=0;
	dfs(0);
	for(auto &p:edges){
		if(dep[p.f]<dep[p.s])
			swap(p.f,p.s);
		if(dep[p.f]-dep[p.s]>treba-2){
			vector<int> ans;
			int tr=p.f;
			while(dep[tr]!=dep[p.s])
				ans.pb(tr),tr=par[tr];
			int b=p.s;
			vector<int> drugi;
			while(tr!=b)
				ans.pb(tr),drugi.pb(b),tr=par[tr],b=par[b];
			ans.pb(tr);
			printf("2\n%i\n",ans.size()+drugi.size());
			for(auto p:ans)
				printf("%i ",p+1);
			reverse(all(drugi));
			for(auto p:drugi)
				printf("%i ",p+1);
			return 0;
		}
	}
	for(int i=0;i<treba-1;i++){
		if(deps[i].size()>=treba){
			printf("1\n");
			for(int j=0;j<treba;j++){
				printf("%i ",deps[i][j]+1);
			}
			return 0;
		}
	}
	return 0;
}
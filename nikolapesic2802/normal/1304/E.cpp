
// Problem : E. 1-Trees and Queries
// Contest : Codeforces Round #620 (Div. 2)
// URL : http://codeforces.com/contest/1304/problem/E
// Memory Limit : 512 MB
// Time Limit : 4000 ms
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

const int N=1e5+5,L=18;
int up[N][L],n;
vector<int> dep(N);
vector<vector<int> > graf(N);
void dfs(int tr,int par){
	for(auto p:graf[tr])
		if(p!=par)
			dep[p]=dep[tr]+1,up[p][0]=tr,dfs(p,tr);
}
int lca(int a,int b){
	if(dep[a]<dep[b])
		swap(a,b);
	int aa=a,bb=b;
	for(int j=L-1;j>=0;j--)
		if(dep[a]-dep[b]>=1<<j)
			a=up[a][j];
	if(a==b)
		return a;
	for(int j=L-1;j>=0;j--)
		if(up[a][j]!=up[b][j])
			a=up[a][j],b=up[b][j];
	return up[a][0];
}
int dst(int a,int b){
	int l=lca(a,b);
	return dep[a]+dep[b]-2*dep[l];
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%i",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(0,0);
	for(int j=1;j<L;j++)
		for(int i=0;i<n;i++)
			up[i][j]=up[up[i][j-1]][j-1];
	int q;
	scanf("%i",&q);
	while(q--){
		int x,y,a,b,k;
		scanf("%i %i %i %i %i",&x,&y,&a,&b,&k);
		x--;y--;a--;b--;
		int di=dst(a,b);
		if(di<=k&&(k-di)%2==0){
			printf("YES\n");
			continue;
		}
		di=dst(a,x)+dst(b,y)+1;
		if(di<=k&&(k-di)%2==0){
			printf("YES\n");
			continue;
		}
		di=dst(b,x)+dst(a,y)+1;
		if(di<=k&&(k-di)%2==0){
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}
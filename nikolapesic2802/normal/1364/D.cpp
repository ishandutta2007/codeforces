
// Problem : D. Ehab's Last Corollary
// Contest : Codeforces - Codeforces Round #649 (Div. 2)
// URL : https://codeforces.com/contest/1364/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {static_assert(D >= 1, "Vector dimension must be greater than zero!");template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1, class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int N=1e5+5;
vector<vector<int> > graf(N);
vector<int> visited(N),par(N,-1);
int a=-1,b=-1;
void dfs(int tr){
	visited[tr]=1;
	for(auto p:graf[tr]){
		if(visited[p]==0){
			par[p]=tr;
			dfs(p);
			continue;
		}
		if(visited[p]==1&&par[tr]!=p){
			a=tr;
			b=p;
		}
	}
	visited[tr]=2;
}
vector<int> color(N,-1);
vector<int> cc[2];
void dfs2(int tr){
	cc[color[tr]].pb(tr);
	for(auto p:graf[tr]){
		if(color[p]==-1)
			color[p]=color[tr]^1,dfs2(p);
	}
}
int main()
{
	int n,k,m;
	scanf("%i %i %i",&n,&m,&k);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%i %i",&u,&v);
		u--;v--;
		if(u<k&&v<k)
			graf[u].pb(v),graf[v].pb(u);
	}
	n=k;
	for(int i=0;i<n;i++){
		if(visited[i]==0)
			dfs(i);
	}
	if(a!=-1){
		par.resize(n);
		vector<int> cyc;
		while(a!=b){
			cyc.pb(a);
			a=par[a];
		}
		cyc.pb(b);
		printf("%i\n%i\n",2,cyc.size());
		for(auto p:cyc){
			printf("%i ",p+1);
		}
		printf("\n");
		return 0;
	}
	vector<int> st;
	for(int i=0;i<n;i++){
		if(color[i]==-1){
			cc[0].clear();
			cc[1].clear();
			color[i]=0;
			dfs2(i);
			if(cc[0].size()<cc[1].size())
				swap(cc[0],cc[1]);
			for(auto p:cc[0])
				st.pb(p);
		}
	}
	printf("1\n");
	for(int i=0;i<(k+1)/2;i++)
		printf("%i ",st[i]+1);
	printf("\n");
	return 0;
}
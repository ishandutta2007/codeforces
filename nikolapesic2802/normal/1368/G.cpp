
// Problem : G. Shifting Dominoes
// Contest : Codeforces - Codeforces Global Round 8
// URL : http://codeforces.com/contest/1368/problem/G
// Memory Limit : 512 MB
// Time Limit : 2000 ms
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

const int N=2e5+5;
vector<vector<int> > graf(N);
int n,m;
int br(int x,int y){
	return x*m+y;
}
vector<int> siz(N);
int dfs(int tr){
	if(siz[tr]!=0)
		return siz[tr];
	siz[tr]=1;
	for(auto p:graf[tr]){
		siz[tr]+=dfs(p);
	}
	return siz[tr];
}
vector<int> up(N,-1);
vector<int> root(N),dep(N),in(N),out(N);
vector<vector<int> > par(N);
int t=0;
void dfs2(int i,int d){
	root[i]=d;
	in[i]=t++;
	for(auto p:graf[i])
		dep[p]=dep[i]+1,dfs2(p,d);
	out[i]=t-1;
}
struct node{
	int sum,l,r;
	bool set;
	node(){
		sum=0;
		l=r=-1;
		set=0;
	}
}e;
vector<node> drvo;
void build(int tr,int l=0,int r=N-1){
	if(l==r)
		return;
	int m=(l+r)>>1;
	drvo.pb(e);
	drvo.pb(e);
	drvo[tr].l=drvo.size()-2;
	drvo[tr].r=drvo.size()-1;
	build(drvo[tr].l,l,m);
	build(drvo[tr].r,m+1,r);
}
int sett(int tr,int qs,int qe,int l=0,int r=N-1){
	if(qs>r||qe<l||drvo[tr].set)
		return tr;
	int nov=drvo.size();
	drvo.pb(drvo[tr]);
	if(qs<=l&&qe>=r){
		drvo[nov].set=1;
		drvo[nov].sum=r-l+1;
		return nov;
	}
	int m=(l+r)>>1;
	drvo[nov].l=sett(drvo[nov].l,qs,qe,l,m);
	drvo[nov].r=sett(drvo[nov].r,qs,qe,m+1,r);
	drvo[nov].sum=drvo[drvo[nov].l].sum+drvo[drvo[nov].r].sum;
	return nov;
}
ll sol=0;
void dfs3(int tr,int root){
	for(auto p:par[tr])
		root=sett(root,in[p],out[p]);
	sol+=drvo[root].sum;
	//printf("%i: %i %i\n",tr,root,drvo[root].sum);
	for(auto p:graf[tr])
		dfs3(p,root);
}
int main()
{
	scanf("%i %i",&n,&m);
	vector<string> mat(n);
	for(int i=0;i<n;i++)
		cin >> mat[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			//printf("%i\n",br(i,j));
			if(mat[i][j]=='U'&&i!=0)
				graf[br(i-1,j)].pb(br(i+1,j)),up[br(i+1,j)]=br(i-1,j);//,printf("%i %i\n",br(i-1,j),br(i+1,j));
			if(mat[i][j]=='D'&&i!=n-1)
				graf[br(i+1,j)].pb(br(i-1,j)),up[br(i-1,j)]=br(i+1,j);//,printf("%i %i\n",br(i+1,j),br(i-1,j));
			if(mat[i][j]=='L'&&j!=0)
				graf[br(i,j-1)].pb(br(i,j+1)),up[br(i,j+1)]=br(i,j-1);//,printf("%i %i\n",br(i,j-1),br(i,j+1));
			if(mat[i][j]=='R'&&j!=m-1)
				graf[br(i,j+1)].pb(br(i,j-1)),up[br(i,j-1)]=br(i,j+1);//,printf("%i %i\n",br(i,j+1),br(i,j-1));
		}
	}
	vector<pair<int,int> > aa;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]=='U')
				par[br(i,j)].pb(br(i+1,j)),par[br(i+1,j)].pb(br(i,j));//,printf("  %i  --  %i\n",br(i,j),br(i+1,j));
			if(mat[i][j]=='L')
				par[br(i,j)].pb(br(i,j+1)),par[br(i,j+1)].pb(br(i,j));//,printf("  %i  --  %i\n",br(i,j),br(i,j+1));
		}
	}
	for(int i=0;i<n*m;i++)
		if(up[i]==-1)
			dfs2(i,i);
	drvo.pb(e);
	build(0);
	for(int i=0;i<n*m;i++)
		if(up[i]==-1)
			dfs3(i,0);
	printf("%lld\n",sol/2);
	return 0;
}
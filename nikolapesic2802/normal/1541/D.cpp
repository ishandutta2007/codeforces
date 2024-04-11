// Problem: D. Tree Array
// Contest: Codeforces - Codeforces Round #728 (Div. 2)
// URL: https://codeforces.com/contest/1541/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1,class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
int ri(){int x;scanf("%i",&x);return x;}
void rd(int&x){scanf("%i",&x);}
void rd(long long&x){scanf("%lld",&x);}
void rd(double&x){scanf("%lf",&x);}
void rd(long double&x){scanf("%Lf",&x);}
void rd(string&x){cin>>x;}
void rd(char*x){scanf("%s",x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}
const int mod=1e9+7; //998244353
int add(int a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b){
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(int a,int b){
    return (long long)a*b%mod;
}
int pwrmod(int x,int k){
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
int inv(int x){
	return pwrmod(x,mod-2);
}
const int N=203;
int f[N][N],fact[N],ifact[N],inv2=inv(2);
int nck(int n,int k){
	return mul(fact[n],mul(ifact[k],ifact[n-k]));
}
vector<vector<int>> graf(N);
vector<int> visited(N),par(N);
int dfs(int tr){
	int sz=1;
	for(auto p:graf[tr]){
		if(!visited[p]){
			visited[p]=1;
			par[p]=tr;
			sz+=dfs(p);
		}
	}
	return sz;
}
vector<int> getPath(int x,int y){
	fill(all(visited),0);
	dfs(x);
	int tr=y;
	vector<int> path={y};
	while(tr!=x){
		tr=par[tr];
		path.pb(tr);
	}
	reverse(all(path));
	return path;
}
int main()
{
	fact[0]=1;
	for(int i=1;i<N;i++)
		fact[i]=mul(fact[i-1],i);
	ifact[N-1]=inv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
		ifact[i]=mul(ifact[i+1],i+1);
	for(int x=0;x<N-2;x++){
		for(int y=0;x+y<N-2;y++){
			int pw=inv(pwrmod(2,x+1));
			for(int j=0;j<=y;j++){
				f[x][y]=add(f[x][y],mul(pw,nck(x+j,x)));
				pw=mul(pw,inv2);
			}
		}
	}
	int n=ri();
	for(int i=1;i<n;i++){
		int a=ri()-1,b=ri()-1;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	int sol=0,invn=inv(n);
	for(int a=1;a<n;a++){
		for(int b=0;b<a;b++){
			vector<int> path=getPath(a,b);
			fill(all(visited),0);
			for(auto p:path)
				visited[p]=1;
			int m=path.size();
			vector<int> siz(m);
			for(int i=0;i<m;i++)
				siz[i]=dfs(path[i]);
			int sansa=mul(siz[0],invn);
			for(int i=1;i<m-1;i++){
				sansa=add(sansa,mul(mul(siz[i],invn),f[i-1][m-2-i]));
			}
			sol=add(sol,sansa);
		}
	}
	printf("%i\n",sol);
	return 0;
}
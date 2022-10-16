
// Problem : F. Strange Addition
// Contest : Codeforces - Educational Codeforces Round 91 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1380/problem/F
// Memory Limit : 256 MB
// Time Limit : 5000 ms
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
template<class T1,class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
int ri(){int x;scanf("%i",&x);return x;}
void rd(int&x){scanf("%i",&x);}
void rd(long long&x){scanf("%lld",&x);}
void rd(double&x){scanf("%lf",&x);}
void rd(long double&x){scanf("%Lf",&x);}
void rd(string&x){cin>>x;}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int mod=998244353;
int add(int a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int mul(int a,int b){
    return (long long)a*b%mod;
}

const int N=5e5+5;
int dig[N];
vector<vector<int> > mat[4*N];
void build(int l=1,int r=N-1,int i=1){
	if(l==r){
		mat[i]={{dig[l]+1,1},{0,0}};
		if(dig[l-1]==1)
			mat[i][1][0]=9-dig[l];
		return;
	}
	int m=(l+r)>>1;
	build(l,m,2*i);
	build(m+1,r,2*i+1);
	mat[i]={{0,0},{0,0}};	
	for(int a=0;a<2;a++)
		for(int b=0;b<2;b++)
			for(int k=0;k<2;k++)
				mat[i][a][b]=add(mat[i][a][b],mul(mat[2*i][a][k],mat[2*i+1][k][b]));
}
void update(int pos,int l=1,int r=N-1,int i=1){
	if(l==r){
		mat[i]={{dig[l]+1,1},{0,0}};
		if(dig[l-1]==1)
			mat[i][1][0]=9-dig[l];
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)
		update(pos,l,m,2*i);
	else
		update(pos,m+1,r,2*i+1);
	for(int a=0;a<2;a++)
		for(int b=0;b<2;b++){
			mat[i][a][b]=0;
			for(int k=0;k<2;k++)
				mat[i][a][b]=add(mat[i][a][b],mul(mat[2*i][a][k],mat[2*i+1][k][b]));
		}
}
int main()
{
	int n,m;
	string s;
	rd(n,m,s);
	for(int i=0;i<n;i++)
		dig[N-n+i]=s[i]-'0';
	build();
	for(int i=0;i<m;i++){
		int x,d;
		scanf("%i %i",&x,&d);
		dig[N-n+x-1]=d;
		update(N-n+x-1);
		if(x!=n)
			update(N-n+x);
		printf("%i\n",mat[1][0][0]);
	}
	return 0;
}
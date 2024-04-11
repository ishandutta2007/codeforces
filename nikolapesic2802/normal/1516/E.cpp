
// Problem: E. Baby Ehab Plays with Permutations
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
void rd(char*x){scanf("%s",x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int mod=1e9+7; //998244353;
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

const int N=402;
int dp[N][N][N/2][2],n,k,fact[N];
int nCk(int n,int k){
	if(k>n||k<0)return 0;
	int tr=1;
	for(int i=n;i>n-k;i--)
		tr=mul(tr,i);
	tr=mul(tr,pwrmod(fact[k],mod-2));
	return tr;
}
int calc(int i,int k,int sw,int p){
	if(sw>=N/2||sw<0)
		return 0;
	if(k<0)
		return 0;
	if(i==0)
		return p==1&&sw==0&&(k%2==0);
	if(dp[i][k][sw][p]!=-1)
		return dp[i][k][sw][p];
	
	dp[i][k][sw][p]=0;
	if(p==1)
		dp[i][k][sw][p]=add(dp[i][k][sw][p],add(calc(i-1,k-1,sw+1,0),calc(i-1,k-1,sw+1,1)));
	else
		dp[i][k][sw][p]=add(dp[i][k][sw][p],add(mul(sw,calc(i,k,sw-1,p)),add(mul(sw,calc(i-1,k,sw-1,0)),mul(sw,calc(i-1,k,sw-1,1)))));
	//printf("dp[%i][%i][%i][%i]: %i\n",i,k,sw,p,dp[i][k][sw][p]);
	return dp[i][k][sw][p];
}
int main()
{
	memset(dp,-1,sizeof dp);
	
	fact[0]=1;
	for(int i=1;i<N;i++)
		fact[i]=mul(fact[i-1],i);
	n=ri();k=ri();
	vector<int> sol(k+1);
	for(int pos=0;pos<=min(n,2*k);pos++){
		if(pos==1)
			continue;
		int way=nCk(n,pos);
		//printf("%i: %i\n",pos,way);
		for(int j=1;j<=k;j++){
			int dd=calc(pos,j,0,1);
			//printf("%i %i: %i\n",pos,j,dd);
			sol[j]=add(sol[j],mul(way,dd));
		}
	}
	for(int i=1;i<=k;i++)
		printf("%i ",sol[i]);
	return 0;
}
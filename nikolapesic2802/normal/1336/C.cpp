
// Problem : C. Kaavi and Magic Spell
// Contest : Codeforces - Codeforces Round #635 (Div. 1)
// URL : https://codeforces.com/contest/1336/problem/C
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
#define D(x) cerr << #x << " is " << (x) << "\n";
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

const int mod=998244353;
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

const int N=3000;
string s,t;
int dp[N][N],n,m;
int calc(int a,int b){
	if(a==0&&b==n-1)
		return 1;
	if(dp[a][b]!=-1)
		return dp[a][b];
	dp[a][b]=0;
	if(a==0&&b>=m-1)
		dp[a][b]=1;
	int d=b-a+1;
	if(a!=0){
		if(a-1<m){
			if(s[d]==t[a-1])
				dp[a][b]=add(dp[a][b],calc(a-1,b));
		}
		else
			dp[a][b]=add(dp[a][b],calc(a-1,b));
	}
	if(b!=n-1){
		if(b+1<m){
			if(s[d]==t[b+1])
				dp[a][b]=add(dp[a][b],calc(a,b+1));
		}
		else
			dp[a][b]=add(dp[a][b],calc(a,b+1));
	}
	return dp[a][b];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin >> s >> t;
	n=s.size();
	m=t.size();
	int sum=0;
	for(int i=0;i<n;i++){
		if(i<m){
			if(s[0]==t[i])
				sum=add(sum,calc(i,i));
		}
		else
			sum=add(sum,calc(i,i));
	}
	sum=add(sum,sum);
	printf("%i\n",sum);
	return 0;
}
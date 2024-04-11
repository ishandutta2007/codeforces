// Problem : F. AND Segments
// Contest : Educational Codeforces Round 84 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1327/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
//template<class T1, class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
//template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}

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
int n;
int solve(vector<pair<int,int> > a,vector<int> b){
	vector<int> s(n);
	for(auto p:b)
		s[p]++;
	for(int i=1;i<n;i++)
		s[i]+=s[i-1];
	int m=b.size();
	vector<int> l(m,-1);
	for(auto &p:a){
		if(p.f)
			p.f=s[p.f-1];
		p.s=s[p.s]-1;
		if(p.f>p.s)
			return 0;
		l[p.s]=max(l[p.s],p.f);
	}
	vector<int> dp(m);
	int ans=1,last=-1;
	for(int i=0;i<m;i++){
		dp[i]=ans;
		ans=add(ans,ans);
		for(;last<l[i];last++){
			if(last==-1)
				ans=sub(ans,1);
			else
				ans=sub(ans,dp[last]);
		}
	}
	return ans;
}
int main(){
	int k,m;
	scanf("%i %i %i",&n,&k,&m);
	vector<vector<pair<int,int> > > on(k);
	vector<vector<int> > cnt(k,vector<int>(n+1));
	for(int i=0;i<m;i++){
		int l,r,x;
		scanf("%i %i %i",&l,&r,&x);
		l--;r--;
		for(int j=0;j<k;j++)
			if(x&(1<<j))
				cnt[j][l]++,cnt[j][r+1]--;
			else
				on[j].pb({l,r});
	}
	int ans=1;
	for(int i=0;i<k;i++){
		for(int j=1;j<n;j++)
			cnt[i][j]+=cnt[i][j-1];
		vector<int> g;
		for(int j=0;j<n;j++)
			if(!cnt[i][j])
				g.pb(j);
		ans=mul(ans,solve(on[i],g));
	}
	printf("%i\n",ans);
	return 0;
}
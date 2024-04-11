
// Problem : B. Johnny and Grandmaster
// Contest : Codeforces - Codeforces Round #647 (Div. 1) - Thanks, Algo Muse!
// URL : http://codeforces.com/contest/1361/problem/B
// Memory Limit : 256 MB
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

bool vece=0;
const ll oo=LLONG_MAX/2;
const int N=1e6+5;
int mul2(int a,int b){
	if((ll)a*b>=N){
		vece=1;
		return 0;
	}
	return a*b;
}
int pwrmod2(int x,int k){
	vece=0;
	int ans=1;
	for(;k;k>>=1,x=mul2(x,x))
		if(k&1)
			ans=mul2(ans,x);
	return ans;
}
int main()
{
	//printf("%i\n",pwrmod(5,99));
	int t;
	scanf("%i",&t);
	while(t--){
		int n,pr;
		scanf("%i %i",&n,&pr);
		map<int,int> cnt;
		for(int i=0;i<n;i++){
			int a;
			scanf("%i",&a);
			cnt[a]++;
		}
		vector<pair<int,int> > ok;
		for(auto p:cnt)
			ok.pb(p);
		reverse(all(ok));
		
		int trDiff=0;
		int totalDiff=0;
		
		int lst=1e6;
		ok.pb({0,0});
		bool oduz=0;
		for(auto p:ok){
			
			int diff=lst-p.f;
			if(p.f==ok[0].f)
				diff=0;
			lst=p.f;
			//printf("%i %i: %i %i\n",p.f,p.s,diff,totalDiff);
			totalDiff=mul(totalDiff,pwrmod(pr,diff));
			if(oduz){
				totalDiff=sub(totalDiff,p.s);
				continue;
			}
			vece=0;
			if(trDiff!=0)
				trDiff=mul2(pwrmod2(pr,diff),trDiff);
			if(vece){
				oduz=1;
				totalDiff=sub(totalDiff,p.s);
				continue;
			}
			for(int i=0;i<p.s;i++){
				if(trDiff>0)
					trDiff--,totalDiff=sub(totalDiff,1);
				else
					trDiff++,totalDiff=add(totalDiff,1);
			}
		}
		printf("%i\n",totalDiff);
	}
	return 0;
}
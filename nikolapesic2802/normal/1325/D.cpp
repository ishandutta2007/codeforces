// Problem : D. Ehab the Xorcist
// Contest : Codeforces Round #628 (Div. 2)
// URL : http://codeforces.com/contest/1325/problem/D
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int L=60;
vector<ll> shortest(ll u,ll v){
	vector<int> cnt(L);
	int imam=-1;
	for(int i=L-1;i>=0;i--){
		int a=!!(u&(1LL<<i)),b=!!(v&(1LL<<i));
		if(a&&b){
			cnt[i]++;
		}
		if(a&&!b){
			if(i==0||(cnt[i]==0&&imam==-1))
				return {-1};
			if(cnt[i]==0){
				for(int j=imam;j>i;j--){
					cnt[j]-=2;
					cnt[j-1]+=4;
				}
			}
			cnt[i]--;
			cnt[i-1]+=2;
		}
		if(!a&&b){
			if(i==0){
				return {-1};
			}
			cnt[i-1]+=2;
		}
		if(cnt[i]>1)
			imam=i;
	}
	int mx=0;
	for(auto p:cnt)
		mx=max(mx,p);
	assert(mx<=3);
	vector<ll> a(mx);
	for(int i=0;i<L;i++){
		for(int j=0;j<cnt[i];j++){
			a[j]^=(1LL<<i);
		}
	}
	return a;
}
int main()
{
	ll u,v;
	cin >> u >> v;
	auto a=shortest(u,v);
	if(a.size()&&a[0]==-1){
		printf("-1\n");
		return 0;
	}
	else{
		printf("%i\n",a.size());
		for(auto p:a)
			printf("%lld ",p);
	}
	return 0;
}
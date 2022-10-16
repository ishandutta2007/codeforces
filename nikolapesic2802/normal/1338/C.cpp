
// Problem : C. Perfect Triples
// Contest : Codeforces Round #633 (Div. 1)
// URL : https://codeforces.com/contest/1338/problem/C
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

vector<ll> find(ll n,ll l,ll r,ll off){
	//printf("%lld %lld %lld %lld\n",n,l,r,off);
	ll skok=(r-l+1)/4;
	assert((r-l+1)%4==0);
	if(n%skok==0){
		if(n/skok==0)
			return {l,2*l+off,l^(2*l+off)};
		if(n/skok==1)
			return {(l+skok),2*(l+skok)+off,(l+skok)^(2*(l+skok)+off)};
		if(n/skok==2)
			return {(l+2*skok),2*(l+skok)+skok+off,(l+2*skok)^(2*(l+skok)+skok+off)};
		if(n/skok==3)
			return {(l+3*skok),2*(l+skok)-skok+off,(l+3*skok)^(2*(l+skok)-skok+off)};
		assert(0);
	}
	int cnt=0;
	while(n>skok)
		n-=skok,l+=skok,cnt++;
	r=l+skok-1;
	if(cnt==2)
		off-=skok;
	if(cnt==3)
		off-=5*skok;
	return find(n,l,r,off);
}
vector<ll> solve(ll n){
	//printf("Solve %i!\n",n);
	ll tr=1;
	while(n){
		if(n==1)
			return {tr,2*tr,3*tr};
		if(n<=tr)
			return find(n-1,tr,2*tr-1,0);
		n-=tr;
		tr*=4;
	}
	assert(0);
	return {};
}
ll test(ll n){
	int ost=(n-1)%3;
	n=(n-1)/3;
	n++;
	auto s=solve(n);
	return s[ost];
}
int main()
{
	/*vector<int> lst;
	set<int> in;
	for(int i=1;i<10000;i++){
		if(in.count(i))
			continue;
		bool nasao=0;
		for(int j=i+1;j<10000;j++){
			if(!in.count(j)&&!in.count(i^j)){
				lst.pb(i);
				lst.pb(j);
				lst.pb(i^j);
				//printf("%i %i %i\n",i,j,i^j);
				in.insert(i);
				in.insert(j);
				in.insert(i^j);
				nasao=1;
				break;
			}
		}
		if(!nasao)
			break;
	}
	//printf("%i\n",test(44));
	//return 0;
	for(int i=0;i<lst.size();i++){
		if(test(i+1)!=lst[i]){
			printf("NOPE %i %i %i\n",i+1,lst[i],test(i+1));
		}
	}
	return 0;*/
	int t;
	scanf("%i",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",test(n));
	}
	return 0;
}
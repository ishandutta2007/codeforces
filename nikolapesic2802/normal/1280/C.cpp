
// Problem : C. Jeremy Bearimy
// Contest : Codeforces Round #607 (Div. 1)
// URL : https://codeforces.com/contest/1280/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double

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

const int N=2e5+5;
vector<vector<pair<int,int> > > graf(N);
pair<int,ll> calcMin(int tr,int par){
	ll cost=0;
	int cnt=1;
	for(auto p:graf[tr]){
		if(p.f==par)
			continue;
		auto t=calcMin(p.f,tr);
		if(t.f)
			cnt++,cost+=p.s;
		cost+=t.s;
	}
	return {cnt&1,cost};
}
int ostalo;
pair<int,ll> calcMax(int tr,int par){
	ll cost=0;
	int cnt=1;
	for(auto p:graf[tr]){
		if(p.f==par)
			continue;
		auto t=calcMax(p.f,tr);
		cnt+=t.f;
		cost+=(ll)p.s*t.f;
		cost+=t.s;
	}
	while(cnt>ostalo)
		cnt-=2,ostalo--;
	return {cnt,cost};
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%i",&t);
	while(t--){
		int k;
		scanf("%i",&k);
		ostalo=k;
		for(int i=0;i<2*k;i++)
			graf[i].clear();
		for(int i=1;i<2*k;i++){
			int a,b,c;
			scanf("%i %i %i",&a,&b,&c);
			a--;b--;
			graf[a].pb({b,c});
			graf[b].pb({a,c});
		}
		printf("%lld %lld\n",calcMin(0,0).s,calcMax(0,0).s);
	}
	return 0;
}
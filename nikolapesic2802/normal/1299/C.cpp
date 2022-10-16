// Problem : C. Water Balance
// Contest : Codeforces Round #618 (Div. 1)
// URL : https://codeforces.com/contest/1299/problem/C
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

const int N=1e6+5;
vector<ld> sum(4*N),mnPrefSum(4*N);
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,a;
	scanf("%i",&n);
	set<pair<int,pair<int,ld> > > s;
	for(int i=0;i<n;i++){
		scanf("%i",&a),s.insert({i,{1,a}});
	}
	auto it=s.begin();
	while(true){
		auto kraj=s.end();
		kraj--;
		if(it==kraj)
			break;
		auto nxt=it;
		nxt++;
		if((*nxt).s.s<(*it).s.s){
			auto tr=*it,sl=*nxt;
			s.erase(it);
			s.erase(nxt);
			tr.s.s*=tr.s.f;
			tr.s.s+=sl.s.s*sl.s.f;
			tr.s.f+=sl.s.f;
			tr.s.s/=tr.s.f;
			s.insert(tr);
			it=s.lower_bound(tr);
			if(it!=s.begin())
				it--;
		}
		else
			it++;
	}
	it=s.begin();
	ld val;
	for(int i=0;i<n;i++){
		if(it!=s.end()&&(*it).f==i)
			val=(*it).s.s,it++;
		printf("%.9Lf\n",val);
	}
	return 0;
}
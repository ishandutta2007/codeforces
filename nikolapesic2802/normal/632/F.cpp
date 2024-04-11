
// Problem : F. Magic Matrix
// Contest : Educational Codeforces Round 9
// URL : https://codeforces.com/contest/632/problem/F
// Memory Limit : 512 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

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

int main()
{
	int n;
	scanf("%i",&n);
	int mat[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%i",&mat[i][j]);
	for(int i=0;i<n;i++)
		if(mat[i][i]!=0)
			return 0*printf("NOT MAGIC");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(mat[i][j]!=mat[j][i])
				return 0*printf("NOT MAGIC");
	bitset<2500> bs[n];
	vector<pair<int,pair<int,int> > > ok;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ok.pb({mat[i][j],{i,j}});
	sort(all(ok));
	vector<pair<int,int> > trChange;
	int last=ok[0].f;
	for(auto p:ok){
		if(last!=p.f){
			for(auto d:trChange)
				if((bs[d.f]&bs[d.s]).count())
					return 0*printf("NOT MAGIC");
			for(auto d:trChange)
				bs[d.f][d.s]=1;
			last=p.f;
			trChange.clear();
		}
		trChange.pb(p.s);
	}
	for(auto d:trChange)
			if((bs[d.f]&bs[d.s]).count())
				return 0*printf("NOT MAGIC");
	printf("MAGIC");
	return 0;
}
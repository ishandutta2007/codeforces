
// Problem : D. Time to Run
// Contest : Codeforces Round #619 (Div. 2)
// URL : https://codeforces.com/contest/1301/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

vector<pair<int,char> > path;
void printPath(){
	printf("YES\n%i\n",path.size());
	for(auto p:path)
		printf("%i %c\n",p.f,p.s);
	exit(0);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	int r=4*n*m-2*n-2*m;
	if(k>r){
		printf("NO\n");
		return 0;
	}
	if(n==1){
		if(k<m){
			path.pb({k,'R'});
			printPath();
		}
		path.pb({m-1,'R'});
		k-=m-1;
		path.pb({k,'L'});
		printPath();
	}
	if(m==1){
		if(k<n){
			path.pb({k,'D'});
			printPath();
		}
		path.pb({n-1,'D'});
		k-=n-1;
		path.pb({k,'U'});
		printPath();
	}
	for(int i=0;i<m-1;i++){
		if(k<n){
			path.pb({k,'D'});
			printPath();
		}
		path.pb({n-1,'D'});
		k-=n-1;
		if(k<n){
			path.pb({k,'U'});
			printPath();
		}
		path.pb({n-1,'U'});
		k-=n-1;
		path.pb({1,'R'});
		k--;
		if(k==0)
			printPath();
	}
	if(k<n){
		path.pb({k,'D'});
		printPath();
	}
	path.pb({n-1,'D'});
	k-=n-1;
	for(int i=0;i<n;i++){
		if(k<m){
			path.pb({k,'L'});
			printPath();
		}
		path.pb({m-1,'L'});
		k-=m-1;
		if(k<m){
			path.pb({k,'R'});
			printPath();
		}
		path.pb({m-1,'R'});
		k-=m-1;
		path.pb({1,'U'});
		k--;
		if(k==0)
			printPath();
	}
	assert(0);
	return 0;
}
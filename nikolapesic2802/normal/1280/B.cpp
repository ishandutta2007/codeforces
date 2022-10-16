
// Problem : B. Beingawesomeism
// Contest : Codeforces Round #607 (Div. 1)
// URL : https://codeforces.com/contest/1280/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%i",&t);
	while(t--){
		int n,m;
		scanf("%i %i",&n,&m);
		vector<string> mat(n);
		for(int i=0;i<n;i++)
			cin >> mat[i];
		int cntA=0,cntB=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(mat[i][j]=='A')
					cntA++;
				else
					cntB++;
		if(cntA==0){
			printf("MORTAL\n");
			continue;
		}
		if(cntB==0){
			printf("0\n");
			continue;
		}
		bool ok;
		ok=1;
		for(int i=0;i<n&&ok;i++)
			if(mat[i][0]!='A')
				ok=0;
		if(ok){
			printf("1\n");
			continue;
		}
		ok=1;
		for(int i=0;i<n&&ok;i++)
			if(mat[i][m-1]!='A')
				ok=0;
		if(ok){
			printf("1\n");
			continue;
		}
		ok=1;
		for(int i=0;i<m&&ok;i++)
			if(mat[0][i]!='A')
				ok=0;
		if(ok){
			printf("1\n");
			continue;
		}
		ok=1;
		for(int i=0;i<m&&ok;i++)
			if(mat[n-1][i]!='A')
				ok=0;
		if(ok){
			printf("1\n");
			continue;
		}
		
		bool red=0;
		for(int i=0;i<n&&!red;i++){
			bool svi=1;
			for(int j=0;j<m&&svi;j++)
				if(mat[i][j]!='A')
					svi=0;
			if(svi)
				red=1;
		}
		if(red){
			printf("2\n");
			continue;
		}
		red=0;
		for(int i=0;i<m&&!red;i++){
			bool svi=1;
			for(int j=0;j<n&&svi;j++)
				if(mat[j][i]!='A')
					svi=0;
			if(svi)
				red=1;
		}
		if(red){
			printf("2\n");
			continue;
		}
		
		if(mat[0][0]=='A'||mat[n-1][0]=='A'||mat[0][m-1]=='A'||mat[n-1][m-1]=='A'){
			printf("2\n");
			continue;
		}
		
		bool ima=0;
		for(int i=0;i<n;i++)
			if(mat[i][0]=='A'||mat[i][m-1]=='A')
				ima=1;
		for(int j=0;j<m;j++)
			if(mat[0][j]=='A'||mat[n-1][j]=='A')
				ima=1;
		if(ima){
			printf("3\n");
			continue;
		}
		printf("4\n");
	}
	return 0;
}
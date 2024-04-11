
// Problem : E. Bombs
// Contest : Codeforces Global Round 7
// URL : http://codeforces.com/contest/1326/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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

const int N=14;
vector<ll> ways[1<<N][N];
int main()
{
	for(int i=0;i<N;i++){
		for(int j=0;j<(1<<N);j++)
			if(j&(1<<i))
				ways[j][i].resize(1<<__builtin_popcount(j)-1);
	}
	int n;
	scanf("%i",&n);
	vector<string> ok(n);
	for(int i=0;i<n;i++)
		cin >> ok[i];
	for(int i=0;i<n;i++)
		ways[1<<i][i][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((i&(1<<j))){
				for(int k=0;k<(1<<__builtin_popcount(i)-1);k++){
					for(int s=0;s<n;s++){
						if(i&(1<<s))
							continue;
						int nv=k*2;
						if(ok[j][s]=='1'){
							nv++;
						}
						ways[i|(1<<s)][s][nv]+=ways[i][j][k];
					}
				}
			}
		}
	}
	vector<ll> cnt(1<<n-1);
	for(int j=0;j<n;j++)
		for(int k=0;k<(1<<n-1);k++)
			cnt[k]+=ways[(1<<n)-1][j][k];
	for(auto p:cnt)
		printf("%lld ",p);
	return 0;
}
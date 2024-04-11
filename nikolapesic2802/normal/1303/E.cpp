
// Problem : E. Erase Subsequences
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/E
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
		string s,t;
	int n,m;
		cin >> s >> t;
		n=s.size(),m=t.size();
		int dp[m+1][m+1],oo=INT_MAX/2;
		vector<vector<int> > nxt(n+1,vector<int>(26));
		vector<int> sl(26,oo);
		for(int i=n;i>=0;i--){
			nxt[i]=sl;
			if(i)
				sl[s[i-1]-'a']=i;
		}
		bool moze=0;
		for(int i=0;i<=m;i++){ //Koliko ide u prvi subsequence
			for(int a=0;a<=i;a++){
				for(int b=0;b<=m-i;b++){
					if(a==0&&b==0){
						dp[a][b]=0;
						continue;
					}
					dp[a][b]=oo;
					if(a){
						int pos=dp[a-1][b];
						if(pos!=oo){
							int karakter=t[a-1]-'a';
							int pos2=nxt[pos][karakter];
							dp[a][b]=min(dp[a][b],pos2);
						}
					}
					if(b){
						int pos=dp[a][b-1];
						if(pos!=oo){
							int karakter=t[i+b-1]-'a';
							int pos2=nxt[pos][karakter];
							dp[a][b]=min(dp[a][b],pos2);
						}
					}
				}
			}
			if(dp[i][m-i]!=oo)
				moze=1;
		}
		printf(moze?"YES\n":"NO\n");
	}
	return 0;
}
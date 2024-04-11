
// Problem : E. Hyakugoku and Ladders
// Contest : Codeforces Round #597 (Div. 2)
// URL : https://codeforces.com/contest/1245/problem/E
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

const int N=10,L=6;
ld expected[N][N];
int up[N][N];
pair<int,int> napred(int x,int y,int koliko){
	if(koliko==0)
		return {x,y};
	if(x&1){ //right
		if(y==N-1)
			return napred(x-1,y,koliko-1);
		return napred(x,y+1,koliko-1);
	}
	if(x==0&&y==0)
		return {-1,-1};
	if(y==0)
		return napred(x-1,y,koliko-1);
	return napred(x,y-1,koliko-1);
}
int main()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%i",&up[i][j]);
	for(int i=0;i<N;i++){
		int j;
		if(i&1)
			j=N-1;
		else
			j=0;
		while(j>=0&&j<N){
			if(i==0&&j==0){
				j++;
				continue;
			}
			int nema=0;
			for(int r=1;r<=L;r++){
				int x,y;
				tie(x,y)=napred(i,j,r);
				if(x==-1)
					nema++;
				else
					expected[i][j]+=min(expected[x][y],expected[x-up[x][y]][y]);
			}
			expected[i][j]/=6;
			//expected[i][j]
			expected[i][j]++;
			expected[i][j]*=(ld)6/(L-nema);
			//printf("%i %i: %lf\n",i,j,expected[i][j]);
			if(i&1)
				j--;
			else
				j++;
		}
	}
	printf("%.10Lf\n",expected[9][0]);
	return 0;
}
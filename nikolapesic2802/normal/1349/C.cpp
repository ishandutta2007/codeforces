
// Problem : C. Orac and Game of Life
// Contest : Codeforces - Codeforces Round #641 (Div. 1)
// URL : https://codeforces.com/contest/1349/problem/C
// Memory Limit : 128 MB
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
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {static_assert(D >= 1, "Vector dimension must be greater than zero!");template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
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

const int N=1001;
int dist[N][N];
bool color[N][N];
bool start[N][N];
int n,m,t;
bool inside(int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
int main()
{
	memset(dist,-1,sizeof(dist));
	ios;
	cin >> n >> m >> t;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<m;j++)
			start[i][j]=s[j]=='1';
	}
	queue<pair<int,int> > q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			bool ima=0;
			for(int k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(inside(x,y)&&start[x][y]==start[i][j]){
					ima=1;
				}
			}
			if(ima){
				dist[i][j]=0;
				color[i][j]=start[i][j];
				q.push({i,j});
			}
		}
	}
	while(q.size()){
		int x=q.front().f,y=q.front().s;
		q.pop();
		for(int k=0;k<4;k++){
			int xx=x+dx[k],yy=y+dy[k];
			if(inside(xx,yy)&&dist[xx][yy]==-1){
				dist[xx][yy]=dist[x][y]+1;
				color[xx][yy]=color[x][y];
				q.push({xx,yy});
			}
		}
	}
	for(int i=0;i<t;i++){
		int x,y;
		ll p;
		cin >> x >> y >> p;
		x--;y--;
		if(dist[x][y]==-1){
			printf("%i\n",start[x][y]);
			continue;
		}
		if(p<=dist[x][y]){
			printf("%i\n",start[x][y]);
			continue;
		}
		ll it=p-dist[x][y];
		it&=1;
		printf("%i\n",start[x][y]^it);
	}
	return 0;
}
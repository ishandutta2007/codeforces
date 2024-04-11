
// Problem : D. Rearrange
// Contest : Codeforces - Codeforces Round #659 (Div. 1)
// URL : http://codeforces.com/contest/1383/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1,class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
int ri(){int x;scanf("%i",&x);return x;}
void rd(int&x){scanf("%i",&x);}
void rd(long long&x){scanf("%lld",&x);}
void rd(double&x){scanf("%lf",&x);}
void rd(long double&x){scanf("%Lf",&x);}
void rd(string&x){cin>>x;}
void rd(char*x){scanf("%s",x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}


vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
int main()
{
	int n=ri(),m=ri();
	vector<vector<int> > a(n,vector<int>(m));
	rd(a);
	set<int,greater<int>> row,col;
	for(int i=0;i<n;i++){
		int mm=0;
		for(int j=0;j<m;j++)
			mm=max(mm,a[i][j]);
		row.insert(mm);
		
	}
	for(int i=0;i<m;i++){
		int mm=0;
		for(int j=0;j<n;j++)
			mm=max(mm,a[j][i]);
		col.insert(mm);
	}
	set<int,greater<int> > inside;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			inside.insert(i*m+j+1);
	for(auto p:row)
		if(inside.count(p))
			inside.erase(p);
	for(auto p:col)
		if(inside.count(p))
			inside.erase(p);
	vector<vector<int> > sol(n,vector<int>(m,-1));
	int x=0,y=0;
	sol[x][y]=n*m;
	row.erase(row.begin());
	col.erase(col.begin());
	while(row.size()||col.size()){
		int tr=max(*row.begin(),*col.begin());
		if(*row.begin()==tr){
			row.erase(row.begin());
			x++;
		}
		if(*col.begin()==tr){
			col.erase(col.begin());
			y++;
		}
		sol[x][y]=tr;
	}
	vector<vector<int> > sta(n,vector<int>(m,-1));
	queue<pair<int,int> > q;
	if(sol[n-1][0]==-1)
		q.push({n-1,0}),sol[n-1][0]=-2;
	while(q.size()){
		int x=q.front().f,y=q.front().s;
		sta[x][y]=0;
		q.pop();
		for(int k=0;k<4;k++){
			int xx=x+dx[k],yy=y+dy[k];
			if(xx<0||xx>=n||yy<0||yy>=m||sol[xx][yy]!=-1)
				continue;
			sol[xx][yy]=-2;
			q.push({xx,yy});
		}
	}
	if(sol[0][m-1]==-1)
		q.push({0,m-1}),sol[0][m-1]=-2;
	while(q.size()){
		int x=q.front().f,y=q.front().s;
		sta[x][y]=1;
		q.pop();
		for(int k=0;k<4;k++){
			int xx=x+dx[k],yy=y+dy[k];
			if(xx<0||xx>=n||yy<0||yy>=m||sol[xx][yy]!=-1)
				continue;
			sol[xx][yy]=-2;
			q.push({xx,yy});
		}
	}
	set<pair<int,pair<int,int> > > options;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(sol[i][j]!=-2)
				continue;
			if(sta[i][j]==0){
				if(sta[i-1][j]==-1&&sta[i][j+1]==-1){
					options.insert({min(sol[i-1][j],sol[i][j+1]),{i,j}});
				}
			}
			if(sta[i][j]==1){
				if(sta[i+1][j]==-1&&sta[i][j-1]==-1){
					options.insert({min(sol[i+1][j],sol[i][j-1]),{i,j}});
				}
			}
		}
	}
	
	for(auto p:inside){
		/*printf("%i!\n",p);
		cout << options << endl;
		if(options.empty()||(*options.rbegin()).f<p){
			printf("-1\n");
			return 0;
		}*/
		int t,x,y;
		t=(*options.rbegin()).f;
		x=(*options.rbegin()).s.f;
		y=(*options.rbegin()).s.s;
		options.erase({t,{x,y}});
		sol[x][y]=p;
		sta[x][y]=-1;
		for(int k=0;k<4;k++){
			int i=x+dx[k],j=y+dy[k];
			if(i<0||i>=n||j<0||j>=m)
				continue;
			if(sta[i][j]==0){
				if(sta[i-1][j]==-1&&sta[i][j+1]==-1){
					options.insert({min(sol[i-1][j],sol[i][j+1]),{i,j}});
				}
			}
			if(sta[i][j]==1){
				if(sta[i+1][j]==-1&&sta[i][j-1]==-1){
					options.insert({min(sol[i+1][j],sol[i][j-1]),{i,j}});
				}
			}
		}
	}
	for(int i=0;i<n;i++,printf("\n"))
		for(int j=0;j<m;j++)
			printf("%i ",sol[i][j]);
	return 0;
}
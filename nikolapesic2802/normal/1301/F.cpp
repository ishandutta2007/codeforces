
// Problem : F. Super Jaber
// Contest : Codeforces Round #619 (Div. 2)
// URL : https://codeforces.com/contest/1301/problem/F
// Memory Limit : 256 MB
// Time Limit : 5000 ms
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

const int N=1001,K=41,oo=INT_MAX/K;
int mapa[N][N],dist[N][N][K],n,m,k;
vector<int> sol(1e5+5,oo);
map<pair<pair<int,int>,pair<int,int> >,int> odma;
vector<pair<pair<int,int>,pair<int,int> > > qq;
vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
bool done[N][N];
int colorDist[K][K];
bool inside(int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
int main()
{
	for(int i=0;i<K;i++)
		for(int j=0;j<K;j++)
			colorDist[i][j]=oo;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%i %i %i",&n,&m,&k);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%i",&mapa[i][j]),mapa[i][j]--;
	int q;
	scanf("%i",&q);
	for(int i=0;i<q;i++){
		int x1,y1,x2,y2;
		scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
		x1--;y1--;x2--;y2--;
		qq.pb({{x1,y1},{x2,y2}});
		odma[{{x1,y1},{x2,y2}}]=i;
	}
	for(int i=0;i<k;i++)
		colorDist[i][i]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int o=0;o<k;o++)
				dist[i][j][o]=oo;
			dist[i][j][mapa[i][j]]=0;
			done[i][j]=1;
			queue<pair<int,int> > q;
			q.push({i,j});
			vector<pair<int,int> > undo;
			while(q.size()){
				int x=q.front().f,y=q.front().s;
				undo.pb({x,y});
				int trDist=dist[i][j][mapa[x][y]];
				if(odma.find({{i,j},{x,y}})!=odma.end())
					sol[odma[{{i,j},{x,y}}]]=min(sol[odma[{{i,j},{x,y}}]],trDist);
				colorDist[mapa[i][j]][mapa[x][y]]=colorDist[mapa[x][y]][mapa[i][j]]=min(colorDist[mapa[x][y]][mapa[i][j]],trDist);
				q.pop();
				for(int k=0;k<4;k++){
					int xx=x+dx[k],yy=y+dy[k];
					if(!inside(xx,yy))
						continue;
					if(!done[xx][yy]&&dist[i][j][mapa[xx][yy]]>=trDist+1)
						done[xx][yy]=1,dist[i][j][mapa[xx][yy]]=trDist+1,q.push({xx,yy});
				}
			}
			for(auto p:undo)
				done[p.f][p.s]=0;
		}
	}
	for(int a=0;a<k;a++)
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				if(colorDist[i][j]>colorDist[i][a]+colorDist[a][j]+1)
					colorDist[i][j]=colorDist[i][a]+colorDist[a][j]+1;
	for(int o=0;o<q;o++){
		int x1,y1,x2,y2;
		x1=qq[o].f.f;
		y1=qq[o].f.s;
		x2=qq[o].s.f;
		y2=qq[o].s.s;
		int gde=odma[{{x1,y1},{x2,y2}}];
		for(int i=0;i<k;i++)
			sol[gde]=min(sol[gde],dist[x1][y1][i]+dist[x2][y2][i]+1);
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				sol[gde]=min(sol[gde],dist[x1][y1][i]+dist[x2][y2][j]+2+colorDist[i][j]);
		printf("%i\n",sol[gde]);
	}
	return 0;
}
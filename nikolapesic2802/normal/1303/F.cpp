// Problem : F. Number of Components
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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

  
void fastscan(int &number)
{
    char c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}


const int N=300,M=300*300+1;
int n,m,q;
int mat[N][N],components;
vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
bool inside(int x,int y){return x>=0&&x<n&&y>=0&&y<m&&mat[x][y]!=-1;}
vector<int> par,siz;
int find(int tr){return tr==par[tr]?tr:par[tr]=find(par[tr]);}
void merge(int a,int b){
  a=find(a),b=find(b);
  if(a==b)
    return;
  if(siz[a]>siz[b])
    swap(a,b);
  siz[b]+=siz[a];
  par[a]=b;
  components--;
}
void update(int x,int y){
  if(!inside(x,y))
    return;
  for(int k=0;k<4;k++){
    int xx=x+dx[k],yy=y+dy[k];
    if(inside(xx,yy)&&mat[xx][yy]==mat[x][y])
      merge(xx*m+yy,x*m+y);
  }
}
void solve(vector<pair<int,int> > boja,int c){
  if(boja.empty())
    return;
  iota(all(par),0);
  fill(all(siz),1);
  int k=boja.size();
  vector<int> sol(k),back;
  for(auto p:boja)
    back.pb(mat[p.f][p.s]),mat[p.f][p.s]=-1;
  components=n*m-boja.size();
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      update(i,j);
  for(int i=k-1;i>=0;i--){
    sol[i]=components;
    components++;
    mat[boja[i].f][boja[i].s]=back[i];
    update(boja[i].f,boja[i].s);
  }
  iota(all(par),0);
  fill(all(siz),1);
  components=0;
  for(int i=0;i<k;i++){
    components++;
    mat[boja[i].f][boja[i].s]=c;
    update(boja[i].f,boja[i].s);
    printf("%i\n",sol[i]+components);
  }
}
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  fastscan(n);
  fastscan(m);
  fastscan(q);
  //cin >> n >> m >> q;
  par.resize(n*m);
  siz.resize(n*m);
  vector<pair<int,int> > tr;
  int last=1;
  for(int i=0;i<q;i++){
    int x,y,c;
    fastscan(x);
    fastscan(y);
    fastscan(c);
    //cin >> x >> y >> c;
    x--;y--;
    if(last!=c)
      solve(tr,last),last=c,tr.clear();
    tr.pb({x,y});
  }
  solve(tr,last);
  return 0;
}
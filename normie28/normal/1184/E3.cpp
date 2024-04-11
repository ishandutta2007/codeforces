/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N = 100000 + 77 , L = 17 , NN = 1000000 + 77;
int n , m , Ev[NN] , Eu[NN] , Ew[NN] , d[N] , Par[N][L] , Mx[N][L] , PD[N] , Pr[NN] , A[NN];
bool M[NN];
vector < int > adj[N] , R[N];
multiset < int > SS[N];
int Find(int x) {return PD[x] <= 0 ? x : (PD[x] = Find(PD[x]));}
inline bool Merge(int v, int u) {
   int nv = Find(v);
   int nu = Find(u);
   if(nv == nu)
      return 0;
   PD[nv] = nu;
   return 1;
}
void dfs(int v , int prev = - 1) {
   for(int i = 1;i < L;++ i)
      Par[v][i] = Par[Par[v][i - 1]][i - 1] , Mx[v][i] = max(Mx[v][i - 1] , Mx[Par[v][i - 1]][i - 1]);
   for(int id : adj[v]) {
      int u = Ev[id] ^ Eu[id] ^ v;
      if(u == prev)
         continue ;
      Par[u][0] = v;
      Mx[u][0] = Ew[id];
      d[u] = d[v] + 1;
      dfs(u , v);
   }
}
inline int GetPar(int v , int k) {
   for(int i = 0;i < L;++ i)
      if((1 << i) & k)
         v = Par[v][i];
   return v;
}
inline int GetLca(int v , int u) {
   if(d[v] < d[u])
      swap(v , u);
   v = GetPar(v , d[v] - d[u]);
   if(v == u)
      return v;
   for(int i = L - 1;i >= 0;-- i)
      if(Par[v][i] != Par[u][i])
         v = Par[v][i] , u = Par[u][i];
   return Par[v][0];
}
inline int GetMax(int v , int k) {
   int r = 0;
   for(int i = 0;i < L;++ i)
      if((1 << i) & k)
         r = max(r , Mx[v][i]) , v = Par[v][i];
   return r;
}
inline int GetPath(int v , int u) {
   int Lca = GetLca(v , u);
   return max(GetMax(v , d[v] - d[Lca]) , GetMax(u , d[u] - d[Lca]));
}
bool CMP(int x , int y) { return Ew[x] < Ew[y]; }
 
 
void dfsCalc(int v = 1 , int prev = - 1) {
   for(int id : adj[v]) {
      int u = Ev[id] ^ Eu[id] ^ v;
      if(u == prev)
         continue ;
      dfsCalc(u , v);
      A[id] = 1e9;
      if(! SS[u].empty())
         A[id] = * SS[u].begin();
      if(SS[u].size() > SS[v].size())
         SS[u].swap(SS[v]);
      for(auto x : SS[u])
         SS[v].insert(x);
      SS[u].clear();
   }
   for(int x : R[v])
      SS[v].erase(SS[v].find(x)) , SS[v].erase(SS[v].find(x));
}
 
int main() {
 
   scanf("%d %d" , & n , & m);
   for(int i = 1;i <= m;++ i)
      scanf("%d %d %d" , Ev + i  , Eu + i , Ew + i) , Pr[i] = i;
   sort(Pr + 1 , Pr + m + 1 , CMP);
   for(int i = 1;i <= m;++ i) {
      int id = Pr[i];
      M[id] = Merge(Ev[id] , Eu[id]);
      if(M[id])
         adj[Ev[id]].push_back(id) , adj[Eu[id]].push_back(id);
   }
   dfs(1);
 
   for(int i = 1;i <= m;++ i)
      if(! M[i])
         A[i] = GetPath(Ev[i] , Eu[i]) , SS[Ev[i]].insert(Ew[i]) , SS[Eu[i]].insert(Ew[i]) , R[GetLca(Ev[i] , Eu[i])].push_back(Ew[i]);
 
   dfsCalc(1);
   assert(SS[1].empty());
   for(int i = 1;i <= m;++ i)
      printf("%d\n" , A[i]);
 
   return 0;
}
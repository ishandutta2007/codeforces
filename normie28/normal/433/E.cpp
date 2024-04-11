
// Problem : B. Game with modulo
// Contest : Codeforces - Codeforces Round #534 (Div. 1)
// URL : https://codeforces.com/contest/1103/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
#define bi BigInt
#define long long long
//---------END-------//
const int N=2e2;
const long mod=1e9+7;
int n,k,dp[N+1][N+1][501][2][2],opt[N+2];
vector<int>lo,hi,nm[N+2];
const int A=2e2;
int W,Nw;
struct Aho_Corasick
{
  int next[20+1],link,f;
}Trie[A+2];
void Aho_Insrt(vector<int>s,int vl)
{
  int now=0;
  for(int i=0;i<s.size();i++)
  {
    int c=s[i];
    if(!Trie[now].next[c])Trie[now].next[c]=++Nw;
    now=Trie[now].next[c];
  }
  Trie[now].f+=vl;
}
void Aho(void)
{
  queue<int>q;q.push(0);
  while(q.size())
  {
    int u=q.front();q.pop();
    int v=Trie[u].link;
    for(int c=0;c<W;c++)
    {
      int nx=Trie[u].next[c];
      if(nx)
      {
        q.push(nx);if(!u)Trie[nx].link=0;
        else Trie[nx].link=Trie[v].next[c];
      }
      else Trie[u].next[c]=Trie[v].next[c];
    }
  }
}
int cal(int now)
{
  if(opt[now]!=-1)return opt[now];
  int ret=0,nnn=now;
  while(now)
  {
    ret+=Trie[now].f;
    now=Trie[now].link;
  }
  return opt[nnn]=ret;
}
vector<int>aa;
long dfs(int st,int now,int kk,int ck,int f)
{
  if(kk>k)return 0;if(st>=aa.size())return f;
  long cnt=0;
  if(dp[st][now][kk][ck][f]!=-1)return dp[st][now][kk][ck][f];
  for(int c=0;c<W;c++)
  {
    int nx=Trie[now].next[c];
    int ex=cal(nx);
    if(ck)
    {
      if(c>aa[st])continue;
      if(c==aa[st])
      {
        cnt=(cnt+dfs(st+1,nx,kk+ex,1,1))%mod;
        continue;
      }
      if(c)cnt=(cnt+dfs(st+1,nx,kk+ex,0,1))%mod;
      else
      {
        if(!f)cnt=(cnt+dfs(st+1,0,kk,0,0))%mod;
        else cnt=(cnt+dfs(st+1,nx,kk+ex,0,1))%mod;
      }
    }
    else
    {
      if(c)cnt=(cnt+dfs(st+1,nx,kk+ex,0,1))%mod;
      else
      {
        if(!f)cnt=(cnt+dfs(st+1,0,kk,0,0))%mod;
        else cnt=(cnt+dfs(st+1,nx,kk+ex,0,1))%mod;
      }
    }
  }
  return dp[st][now][kk][ck][f]=cnt;
}
int main()
{
    fio;
  cin>>n>>W>>k;int x;cin>>x;
  while(x--){int z;cin>>z;lo.push_back(z);}
  cin>>x;while(x--){int z;cin>>z;hi.push_back(z);}
  for(int i=1;i<=n;i++)
  {
    vector<int>v;cin>>x;
    while(x--){int z;cin>>z;v.push_back(z);}
    int vl;cin>>vl;Aho_Insrt(v,vl);
  }
  Aho();memset(opt,-1,sizeof(opt));
  aa=hi;long one,two;memset(dp,-1,sizeof(dp));
  two=dfs(0,0,0,1,0);memset(dp,-1,sizeof(dp));
  aa=lo;one=dfs(0,0,0,1,0);
  long df=(two-one+mod)%mod;
 
  int now=0;
  for(auto x:lo)
  {
    now=Trie[now].next[x];
    k-=cal(now);
  }
  if(k>=0)df=(df+1)%mod;
  cout<<df<<endl;
  return 0;
}
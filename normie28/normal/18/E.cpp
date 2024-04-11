
// Problem : E. Flag 2
// Contest : Codeforces - Codeforces Beta Round #18 (Div. 2 Only)
// URL : https://codeforces.com/problemset/problem/18/E
// Memory Limit : 128 MB
// Time Limit : 2000 ms
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
const int oo=1e9;  
const int mm=504;  
const int nn=26;  
char grap[mm][mm];  
int m,n;  
int f[mm][nn][nn];  
int a_path[mm][nn][nn],b_path[mm][nn][nn];  
int cost(int x,int a,int b)
{  
  a+='a';b+='a';  
  int ret=0;  
  for(int i=0;i<n;i++)if(i&1)ret+=(a!=grap[x][i]);else ret+=(b!=grap[x][i]);  
  return ret;  
}  
void print(int z,int x,int y)  
{  
  if(z)print(z-1,a_path[z][x][y],b_path[z][x][y]);  
  for(int i=0;i<n;i++)  
    if(i&1)cout<<char(x+'a');  
  else cout<<char(y+'a');  
  cout<<endl;
}  
int main()  
{  
fio;
cin>>m>>n;
    for(int i=0;i<m;i++)cin>>grap[i];  
    for(int i=0;i<nn;i++)  
      for(int j=0;j<nn;j++)
    {  
      if(i==j)f[0][i][j]=oo;  
      else f[0][i][j]=cost(0,i,j);  
    }  
    for(int i=1;i<m;i++)  
      for(int A=0;A<nn;A++)  
      for(int B=0;B<nn;B++)  
    {  
      if(A==B)continue;  
      int cur=cost(i,A,B); 
      int mid,_min=oo,x=-1,y=-1;  
      for(int a=0;a<nn;a++)  
        for(int b=0;b<nn;b++)  
      { if(a==A||b==B||a==b)continue;  
        if(_min>f[i-1][a][b]){_min=f[i-1][a][b];x=a;y=b;}  
      }  
      f[i][A][B]=_min+cur;a_path[i][A][B]=x;b_path[i][A][B]=y;
    }  int _min=oo,x,y;  
      for(int a=0;a<nn;a++)  
        for(int b=0;b<nn;b++)  
      { if(a==b)continue;  
        if(_min>f[m-1][a][b]){_min=f[m-1][a][b];x=a;y=b;}  
      }  
    cout<<f[m-1][x][y]<<endl;  
    print(m-1,x,y);  
  }
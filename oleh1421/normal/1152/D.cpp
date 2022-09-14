#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int n;
int dp0[1001][1001];
int dp1[1001][1001];
bool used[1001][1001];
pair<int,int> dfs(int i,int j){
              if (i==n && j==n) return {0,0};
              if (used[i][j]) return {dp1[i][j],dp0[i][j]};
              int cur0=0;
              if (i>j){
                  pair<int,int>x=dfs(i,j+1);
                  cur0+=max(x.first,x.second);
              }
              if (i<n){
                  pair<int,int>x=dfs(i+1,j);
                  cur0+=max(x.first,x.second);
              }
              int cur1=0;
              bool ok=false;
              if (i>j){
                  pair<int,int>x=dfs(i,j+1);
                  if (x.first<=x.second) ok=true;
                  cur1+=max(x.first,x.second);
              }
              if (i<n){
                  pair<int,int>x=dfs(i+1,j);
                  if (x.first<=x.second) ok=true;
                  cur1+=max(x.first,x.second);
              }
              cur1+=ok;
              cur0%=1000000007ll;
              cur1%=1000000007ll;
              dp0[i][j]=cur0;
              dp1[i][j]=cur1;
              used[i][j]=true;
              return {cur1,cur0};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    pair<int,int>x=dfs(0,0);
    cout<<max(x.first,x.second);
    return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

const int N = (int)5e5 + 9;
int dp[N];
int A[N];
int len[N];

int Q(int l,int r){
  if(l > r)
    return 0;
  if(l == 0)
    return A[r];
  return A[r] - A[l - 1];
}

int main(){
  fastIO;
  int n,k,d;
  cin >>n >> k >> d;
  dp[0] = 1;
  A[0] = 1;
  for(int i = 1;i <= n;i ++ )
    cin >> len[i];
  sort(len + 1, len + n + 1);
  int p = 1;
  for(int j = 1;j <= n;j ++ ){
    while(len[j] - len[p] > d){
      p ++ ;
    }
    if(j-p+1 >= k){
      if(Q(p-1, j - k) >= 1){
        dp[j] = 1;
      }
    }
    A[j] += A[j - 1];
    A[j] += dp[j];
  }
  if(dp[n] == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
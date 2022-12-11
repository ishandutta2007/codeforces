#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)1e6 + 913;
int dp[N];
int prefix[N][10];

int rez(int u){
  int a = 1;
  while(u > 0){
    a = max(a,a*(u%10));
    u/=10;
  }
  return a;
}

int main(){
  fastIO;
  for(int i = 1;i<N;i++){
    if(i < 10)dp[i]=i;
    else dp[i]=dp[rez(i)];
    prefix[i][dp[i]]=1;
    for(int j = 1;j<=9;j++)prefix[i][j]+=prefix[i-1][j];
  }
  int q;
  cin >> q;
  while(q--){
    int l,r,k;
    cin >> l >> r >> k;
    cout << prefix[r][k]-prefix[l-1][k] << "\n";
  }
  return 0;
}
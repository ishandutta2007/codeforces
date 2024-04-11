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
#define ones(a) __builtin_popcount(a)

const int N = 5005;
int a[N];
int ans[N];

map<int, int> cc;
int p = 1;
int cnt[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1;i <= n;i ++ ){
    cin >> a[i];
    for(int j = 2;j * j <= ab(a[i]); j ++ ){
      while(a[i] % (j*j) == 0){
        a[i] /= j*j;
      }
    }
    if(a[i] == 0)
      continue;
    if(cc[a[i]] == 0){
      cc[a[i]] = p;
      p ++ ;
    }
    a[i] = cc[a[i]];
  }
  int dist = 0;
  for(int i = 1;i <= n;i ++ ){
    for(int j = 0;j < N;j ++ )
      cnt[j] = 0;
    dist = 0;
    for(int j = i;j <= n;j ++ ){
      cnt[a[j]] ++ ;
      if(a[j] != 0 and cnt[a[j]] == 1)
        dist ++ ;
      ans[max(1, dist)] ++ ;
    }
  }
  for(int i = 1;i <= n;i ++ )
    cout << ans[i] << " ";
  return 0;
}
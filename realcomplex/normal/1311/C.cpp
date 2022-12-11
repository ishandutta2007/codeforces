#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int cnt[N];
int a[N];
ll r[26];

void solve(){
  for(int i = 0 ; i < 26; i ++ )
    r[i]=0ll;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n+1; i ++ )
    cnt[i] = 0;
  int x;
  char f;
  for(int i = 1; i <= n; i ++ ){
    cin >> f;
    a[i] = f - 'a';
  }
  cnt[n]=1;
  for(int i = 1; i <= m ; i ++ ){
    cin >> x;
    cnt[x] ++ ;
  }
  for(int i = n; i >= 1; i -- )
    cnt[i]+=cnt[i+1];
  for(int i = 1; i <= n; i ++ ){
    r[a[i]] += cnt[i];
  }
  for(int i = 0; i < 26; i ++ )
    cout << r[i] << " ";
  cout << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ ){
    solve();
  }
  return 0;
}
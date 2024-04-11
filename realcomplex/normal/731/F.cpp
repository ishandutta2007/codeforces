#pragma optimize ("O3")
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

const int N = (int)2e5 + 123;
int cnt[N];
int pref[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int x;
  ll sum = 0;
  for(int i = 0;i < n;i ++ ){
    cin >> x;
    cnt[x] ++ ;
    sum += x;
  }
  if(cnt[1] != 0){
    cout << sum << "\n";
    return 0;
  }
  for(int i = 1; i < N; i ++ ){
    pref[i] = pref[i - 1] + cnt[i];
  }
  ll ans = 0;
  int l , r;
  sum = 0;
  for(int i = 2; i < N; i ++ ){
    if(cnt[i] == 0)
      continue;
    sum = 0;
    for(int j = 1; i * j < N; j ++ ){
      l = i * j;
      r = l + i - 1;
      r = min(r, N - 1);
        sum +=(ll)(pref[r] - pref[l-1]) * (ll)l;
    }
    ans = max(ans,sum);
  }
  cout << ans;
  return 0;
}
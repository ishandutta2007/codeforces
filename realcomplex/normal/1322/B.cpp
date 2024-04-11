#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int LOG = 26;
const int M = (1 << LOG);
const int N = (int)4e5 + 9;
int cnt[M];
int a[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ )
    cin >> a[i];
  int lim;
  int ans = 0;
  int l, r;
  int cur;
  ll sum = 0;
  for(int i = 1 ; i < LOG; i ++ ){
    lim = (1 << i);
    for(int j = 0 ; j < lim; j ++ )
      cnt[j]=0;
    for(int j =1; j <= n; j ++ ){
      cnt[a[j]%lim] ++ ;
    }
    l=(1<<(i-1));
    r = lim-1;
    cur = 0;
    sum = 0;
    for(int j = l ; j <= r; j ++ ){
      cur += cnt[j];
    }
    for(int j = 0 ; j < lim; j ++ ){
      if(j >= l && j <= r)
        sum += cnt[j]*1ll*(cur-cnt[j]);
      else
        sum += cnt[j]*1ll*cur;
      cur -= cnt[r];
      l--;
      r--;
      if(l>=0)cur += cnt[l];
    }
    r = lim - 1;
    l = (1 << i) + (1 << (i - 1));
    cur = 0;
    for(int j = 0 ; j < lim; j ++ ){
      if(l < lim){
        if(j >= l && j <= r)
          sum += cnt[j]*1ll*(cur-cnt[j]);
        else
          sum += cnt[j]*1ll*cur;
      }
      l--;
      if(l < lim)
        cur += cnt[l];
    }
    sum /= 2;
    for(int j = 0 ; j < lim; j ++ ){
      if((j + j) % lim >= lim/2){
        sum += (cnt[j] * 1ll * (cnt[j] - 1))/2ll;
      }
    }
    if((sum & 1)){
      ans |= (1 << (i-1));
    }
  }
  cout << ans;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int cnt[2049];

int main(){
  fastIO;
  int testc;
  cin >> testc;
  int cur, pv;
  for(int t =0 ; t < testc; t ++ ){
    int n;
    cin >> n;
    for(int i = 0 ;i  <= 2048 ; i ++ ){
      cnt[i] = 0;
    }
    int a;
    for(int i = 0 ; i < n; i ++ ){
      cin >> a;
      if(a <= 2048)cnt[a] ++ ;
    }
    for(int i = 1;i <= 11; i ++ ){
      cur = (1 << i);
      pv = (1 << (i-1));
      cnt[cur] += cnt[pv]/2;
    }
    if(cnt[2048] > 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
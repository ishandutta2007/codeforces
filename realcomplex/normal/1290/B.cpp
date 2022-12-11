#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int AL = 26;
const int N = (int)2e5 + 9;
int cnt[AL][N];

int main(){
  fastIO;
  string t;
  cin >> t;
  int n = t.size();
  int d;
  for(int i = 1; i <= n; i ++ ){
    d = t[i - 1] - 'a';
    cnt[d][i] ++ ;
    for(int j = 0 ; j < AL; j ++ )
      cnt[j][i] += cnt[j][i-1];
  }
  int q;
  cin >> q;
  int l, r;
  int mx;
  for(int i = 0 ;i < q; i ++ ){
    cin >> l >> r;
    mx = 0;
    for(int j = 0 ;j < AL ;j ++ )
      mx+=(cnt[j][r]-cnt[j][l-1]>0);
    if(mx > 2 || l == r || t[l-1] != t[r-1]){
      cout << "Yes\n";
    }
    else{
      cout << "No\n";
    }
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int AL = 26;
int cnt[AL];

int dd;

int main(){
  fastIO;
  string s;
  int n;
  cin >> s >> n;
  int ix;
  for(char x : s){
    ix = x - 'a';
    cnt[ix] ++ ;
    if(cnt[ix] == 1)
      dd ++ ;
  }
  if(n < dd){
    cout << -1 << "\n";
    return 0;
  }
  int l = 1, r = 1000;
  int md;
  int sum;
  while(l < r){
    md = (l + r)/2;
    sum = 0;
    for(int x = 0; x < AL; x ++ )
      sum += (cnt[x] + md - 1) / md;
    if(sum <= n)
      r = md;
    else
      l = md + 1;
  }
  string ans;
  for(int x = 0; x < AL; x ++ ){
    for(int j = 0;j < (cnt[x] + r - 1) / r; j ++ )
      ans += char(x + 'a');
  }
  while(ans.size() < n){
    ans += 'z';
  }
  cout << r << "\n" << ans;
  return 0;
}
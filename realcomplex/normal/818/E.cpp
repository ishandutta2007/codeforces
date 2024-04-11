#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

vector<int>pr;
vector<int>cnt;

void fin(int k){
  int n;
  for(int i = 2;i * i <= k; i ++ ){
    if(k % i != 0)
      continue;
    pr.push_back(i);
    cnt.push_back(0);
    n = cnt.size();
    n -- ;
    while(k % i == 0){
      cnt[n] ++ ;
      k /= i;
    }
  }
  if(k != 1){ 
    cnt.push_back(1);
    pr.push_back(k);
  }
}

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  if(k == 1){
    cout << (1LL * n * (n + 1))/2;
    return 0;
  }
  fin(k);
  int p = pr.size(); // since k >= 1, p >= 1
  int sum[n][p];
  memset(sum, 0, sizeof sum);
  int x;
  for(int i = 0;i < n;i ++ ){
    cin >> x;
    for(int y = 0; y < pr.size(); y ++ ){
      while(x % pr[y] == 0){
        x /= pr[y];
        sum[i][y] ++ ;
      }
    }
  }
  int current[p];
  memset(current, 0, sizeof current);
  int pp = 0;
  bool ok;
  ll ans = 0;
  ll bad_segments;
  for(int i = 0;i < n;i ++ ){
    
    for(int j = 0;j < p;j ++ ){
      current[j] += sum[i][j];
      //cout << current[j] << " ";
    }
      
    do{
      ok = true;
      for(int j = 0;j < p;j ++ ){
        if(current[j]-sum[pp][j] < cnt[j]){
          ok = false;
        }
      }
      if(ok){
        for(int j = 0; j < p;j ++ ){
          current[j] -= sum[pp][j];
        }
        pp ++ ;
      }
    }while(pp < i and ok);
    ok = true;
    for(int j = 0;j < p;j ++ ){
      if(current[j] < cnt[j]){
        ok = false;
      }
    }
    if(ok){
      bad_segments = i-pp;
      ans += (i + 1) - bad_segments;
    }
  }
  cout << ans << "\n";
  return 0;
}
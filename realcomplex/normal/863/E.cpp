#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const int N = (int)1e6 + 911;
int cnt[N];
map<int, int> compr;

int main(){
  fastIO;
  int n;
  cin >> n;
  int l[n], r[n];
  vector<int> pi;
  for(int i = 0;i < n;i ++ ){
    cin >> l[i] >> r[i];
    pi.push_back(l[i]);
    pi.push_back(r[i]);
    pi.push_back(r[i] + 1);
  }
  sort(pi.begin(), pi.end());
  pi.resize(unique(pi.begin(), pi.end()) - pi.begin());
  for(int i = 0;i < pi.size(); i ++ ){
    compr[pi[i]] = i + 1;
  }
  for(int i = 0;i < n;i ++ ){
    l[i] = compr[l[i]];
    r[i] = compr[r[i]];
    cnt[l[i]] ++ ;
    cnt[r[i] + 1] -- ;
  }
  for(int i = 1; i < N; i ++ ){
    cnt[i] += cnt[i - 1];
  }
  for(int i = 1;i < N; i ++ ){
    cnt[i] = (cnt[i] >= 2);
  }
  for(int i = 1;i < N; i ++ ){
    cnt[i] += cnt[i - 1];
  }
  for(int i = 0;i < n;i ++ ){
    if(cnt[r[i]] - cnt[l[i] - 1] == r[i] - l[i] + 1){
      cout << i + 1;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
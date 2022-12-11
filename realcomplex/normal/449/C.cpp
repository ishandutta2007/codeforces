#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

#define MAX 123456

bitset<MAX> pr;

void sieve(){
  for(int i = 0;i < MAX; i ++){
    pr[i] = 1;
  }
  for(int i = 2;i < MAX;i ++ ){
    if(!pr[i]){
      continue;
    }
    for(int j = 2; j * i < MAX; j ++){
      pr[i * j] = 0;
    }
  }
}

int main(){
  fastIO;
  sieve();
  int n;
  cin >> n;
  if(n == 1 or n == 2){
    cout << "0\n";
    return 0;
  }
  set<int>use;
  for(int i = 2;i <= n;i ++)
    use.insert(i);
  for(int j = n/2+1; j <= n;j ++)
    if(pr[j]){
      use.erase(j);
    }
  vector<pii>match;
  int cnt;
  for(int i = 3; i <= n/2;i ++){
    if(!pr[i]){
      continue;
    }
    vector<int>kk;
    cnt = 0;
    for(int j = 1;j * i <= n;j ++ ){
      cnt += use.count(j*i);
    }
    for(int j = 1;j * i <= n; j ++ ){
      if(use.count(j*i)){
        if(j != 2 or (j == 2 and cnt%2==0))kk.push_back(j * i);
      }
    }
    for(int j = 1;j < (int)kk.size(); j +=2 ){
      use.erase(kk[j]);
      use.erase(kk[j - 1]);
      match.push_back(mp(kk[j], kk[j - 1]));
    }
  }
  vector<int>lf;
  for(auto x : use)
    if(x%2==0)
      lf.push_back(x);
  for(int i = 1;i < (int)lf.size(); i +=2 )
    match.push_back(mp(lf[i], lf[i - 1]));
  cout << match.size() << "\n";
  for(auto x : match)
    cout << x.fi << " " << x.se << "\n";
  return 0;
}
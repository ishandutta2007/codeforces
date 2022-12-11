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
#define ones(a) __builtin_popcount(a)

const int N = (int)2e5 + 9;
int n;
int arr[N];

ll Calc(int median){
  int p = 0;
  ll cur = 0, ans = 0;
  map<int, int> cnt;
  for(int i = 0;i < n;i ++ ){
    cnt[p] ++ ;
    if(arr[i] < median)
      cur -= cnt[--p]  ;
    else
      cur += cnt[p++];
    ans += cur;
  }
  return ans;
}

int main(){
  fastIO;
  int m;
  cin >> n >> m;
  for(int i = 0;i < n;i ++ ){
    cin >> arr[i];
  }
  cout << Calc(m) - Calc(m + 1);
  return 0;
}
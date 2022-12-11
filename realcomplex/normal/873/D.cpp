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

const int N = (int)1e5 + 9;
int a[N];
int k;

void unsort(int l, int r){
  if(k == 0)
    return;
  if(r - l == 1)
    return;
  int md = (l + r) / 2;
  swap(a[md], a[md - 1]);
  k -= 2;
  unsort(l, md);
  unsort(md, r);
}

int main(){
  fastIO;
  int n;
  cin >> n >> k;
  if(k % 2 == 0){
    cout << "-1\n";
    return 0;
  }
  k -- ;
  for(int i = 0; i < n;i ++ )
    a[i] = i + 1;
  unsort(0, n);
  if(k != 0){
    cout << -1 << "\n";
    return 0;
  }
  for(int i = 0;i < n;i ++ ){
    cout << a[i] << " ";
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int a[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  ll neg = 0, pos = 0;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    if(a[i] > 0) 
      a[i] = 0;
    else
      a[i] = 1;
  }
  int p0 = 1, p1 = 0;
  int cur = 0;
  for(int i = 1; i <= n; i ++ ){
    cur ^= a[i];
    if(cur == 1){
      neg += p0;
      pos += p1;
    }
    else{
      neg += p1;
      pos += p0;
    }
    if(cur == 0) p0 ++ ;
    else p1 ++ ;
  }
  cout << neg << " " << pos;
  return 0;
}
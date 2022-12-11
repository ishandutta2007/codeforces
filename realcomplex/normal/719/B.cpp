#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)1e5 + 9;
char cr[N];
int n;

int ans(int bit){
  int gr = 0, rd = 0;
  for(int i = 0 ;i < n; i ++ ){
    if(i % 2 == bit){
      if(cr[i] == 'b')
        gr ++ ;
    }
    else{
      if(cr[i] == 'r')
        rd ++ ;
    }
  }
  return max(gr , rd);
}

int main(){
  fastIO;
  cin >> n;
  for(int i = 0; i < n; i ++ ){
    cin >> cr[i];
  }
  cout << min(ans(0),ans(1));
  return 0;
}
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

const int T = 60 * 24;

bool is(int x){
  while(x > 0){
    if(x % 10 == 7)
      return true;
    x /= 10;
  }
  return false;
}

bool has(int cd){
  int hr = cd / 60;
  int min = cd % 60;
  return is(hr) or is(min);
}

int main(){
  fastIO;
  int x;
  cin >> x;
  int hi,mi;
  cin >> hi >> mi;
  int cd = hi * 60 + mi;
  int cnt = 0;
  while(!has(cd)){
    cd-=x;
    cd += T;
    cd %= T;
    cnt++;
  }
  cout << cnt;
  return 0;
}
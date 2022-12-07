#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  long long n, m, q;
  cin >> n >> m >> q;

  long long g = __gcd(n, m);


  while(q--) {
    long long sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    --sy; --ey;

    if(sx == 1) sy /= n / g;
    else sy /= m / g;
    if(ex == 1) ey /= n / g;
    else ey /= m / g;


    if(sy == ey) cout << "YES" << endl;
    else cout << "NO" << endl;

  }

  return 0;
}
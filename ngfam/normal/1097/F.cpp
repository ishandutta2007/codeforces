#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 7007;

typedef bitset < M > item;

int n, q;
item a[N];
item f[M];
int prime[M];
int mobius[M];
item divisors[M];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  for(int i = 1; i < M; ++i) {
    mobius[i] = 1;
    for(int j = i; j < M; j += i) {
      divisors[j][i] = 1;
    }
  }

  for(int i = 2; i < M; ++i) {
    if(!prime[i]) for(int j = i; j < M; j += i) {
      prime[j] = 1;
      mobius[j] *= -1;
      if((j / i) % i == 0) mobius[j] = 0;
    }
  }

  for(int i = 1; i < M; ++i) {
    for(int j = i; j < M; j += i) {
      f[i][j] = (mobius[j / i] != 0);
    }
  }

  cin >> n >> q;


  while(q--) {
    int t, x, y, z;
    cin >> t;

    if(t == 1) {
      cin >> x >> y;
      a[x] = divisors[y];
    }
    if(t == 2) {
      cin >> x >> y >> z;
      a[x] = (a[y] ^ a[z]);
    }
    if(t == 3) {
      cin >> x >> y >> z;
      a[x] = (a[y] & a[z]);
    }
    if(t == 4) {
      cin >> x >> y;
      cout << (a[x] & f[y]).count() % 2;
    }
  }

	return 0;
}
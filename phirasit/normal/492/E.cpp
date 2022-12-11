#include <iostream>

#define N 1000010

using namespace std;

long long a[N], c[N];
long long n, m, dx, dy;

int main() {
	cin >> n >> m >> dx >> dy;
	int ans = 0;
	for(int i = 0;i < n;i++) {
		a[(i * dx) % n] = (i * dy) % n;
	}
  for(int i = 0;i < m;i++){
  	long long x, y;
  	cin >> x >> y;
    long long aux = (n + y - a[x]) % n;
    c[aux]++;
    if(c[aux] > c[ans]) {
			ans = aux;
		}
  }
  cout << 0 << " " << ans << endl;
	return 0;
}
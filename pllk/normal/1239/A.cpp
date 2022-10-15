#include <iostream>

using namespace std;

#define M 1000000007

typedef long long ll;

ll t[101010];

int main() {
	int n, m;
	cin >> n >> m;
	t[0] = 1;
	t[1] = 1;
	for (int i = 2; i <= 100000; i++) {
		t[i] = (t[i-2]+t[i-1])%M;
	}
	ll u = t[n]*2+t[m]*2-2;
	u = (u%M+M)%M;
	cout << u << "\n";
}
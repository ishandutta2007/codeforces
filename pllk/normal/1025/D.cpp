#include <iostream>

using namespace std;

int n;
int x[777];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}

int gg[777][777];

bool vv[777][777][2];
bool dd[777][777][2];

int check(int a, int b, int c) {
	if (a > b) return true;
	if (vv[a][b][c]) return dd[a][b][c];
	int g = (c == 0) ? a-1 : b+1;
	bool ok = false;
	for (int i = a; i <= b; i++) {
		if (check(a,i-1,1) && check(i+1,b,0) && gg[g][i]) {
			ok = true;
			break;
		}
	}
	vv[a][b][c] = true;
	dd[a][b][c] = ok;
	return ok;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= n+1; j++) {
			gg[i][j] = gg[j][i] = gcd(x[i],x[j]) >= 2;
		}
	}
	if (check(1,n,0)) cout << "Yes\n";
	else cout << "No\n";
}
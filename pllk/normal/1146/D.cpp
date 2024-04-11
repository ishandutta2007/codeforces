#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

int m, a, b;
set<int> s;
int z[1222333];
int c;
ll tt;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}

ll sum(ll a, ll b) {
	return b*(b+1)/2-(a-1)*((a-1)+1)/2;
}

int main() {
	cin >> m >> a >> b;
	int g = gcd(a,b);
	s.insert(0);
	z[0] = 1;
	for (int x = 0; x <= m; x++) {
		while (s.size() && *s.begin()+a <= x) {
			int u = *s.begin()+a;
			if (z[u]) continue;
			z[u] = 1;
			c++;
			s.erase(s.begin());
			s.insert(u);
			while (true) {
				u -= b;
				if (u < 0 || z[u]) break;
				z[u] = 1;
				c++;
				s.insert(u);
			}
		}
		if (x != 0 && x%g == 0 && x/g == c) {
			int e = m-x+1;
			tt += sum(c+1,c+1+e/g-1)*g;
			tt += (c+1+e/g)*(e%g);
			break;
		}
		tt += c+1;
	}
	cout << tt << "\n";
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

	string a, b;
	cin >> a >> b;
	int p1 = 0, p2 = 0, q = 0;
	for (int i = 0; i < a.size(); i++) {
            if (a[i] == '-') {p1--;}
            else {p1++;}

            if (b[i] == '-') {p2--;}
            else if (b[i] == '+') {p2++;}
            else {q++;}
	}

	if (abs(p2 - p1) > q) {cout << 0; return 0;}

	double ans = 0;

      for (int i = 0; i < (1 << q); i++) {
            int tmp = i;

            int tmpp = p2;
            for (int j = 0; j < q; j++) {
                  if (tmp % 2) {tmpp++;}
                  else {tmpp--;}

                  tmp /= 2;
            }

            if (tmpp == p1) {ans += 1;}
      }

      cout << fixed << setprecision(12) << ans/(1 << q);

	return 0;
}
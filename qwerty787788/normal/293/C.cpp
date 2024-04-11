#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int res = 0;

void add(int a, int b, int c) {
   // a <= b <= c;
   if (a < b && b < c) {
       res += 6;
       return;
   }
   if (a == b && b == c) {
       res += 1;
       return;
   }
   res += 3;
}

long long n;
vector<int> divi;

int main() {
	cin >> n;
	if (n % 3 != 0) {
		cout << 0 << endl;
		return 0;
	}
	int a_max = pow(n / 24., 1/3.);
	long long m = n / 3;
	int b_max = pow(n / 6., 1/3.);
	for (int i = 2; i <= b_max + a_max; i++)
		if (m % i == 0)
			divi.push_back(i);
	for (int a = 1; a <= a_max; a++)
		for (int bi = 0; bi < divi.size(); bi++) {
			int sum = divi[bi];
			int b = sum - a;
			if (b < a || b > b_max)
				continue;
			long long K = m / sum;
			long long B = sum * 1L * sum;

			long long di = B - 4 * (a * 1L * b - K);

			double desc = sqrt(di+0.);
			int desc2 = (int) (desc + 0.5);
			if (abs(desc - desc2) > 0.000001)
				continue;
			int c = (-sum + desc2) / 2;
			if (c < b)
				continue;
			add(a, b, c);
		}
	cout << res << endl;
}
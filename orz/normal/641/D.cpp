#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

pair <double, double> squr(double sum, double prod)
{
	sum /= 2;
	if (sum * sum < prod)
		prod = 0;
	else
		prod = sqrt(sum * sum - prod);
	return pair<double, double>(sum - prod, sum + prod);
}

int main()
{
	int n, i;
	double *l, *r, *s, *t;
	cin >> n;
	pair <double, double> p;
	l = new double[n] - 1;
	r = new double[n] - 1;
	s = new double[n] - 1;
	t = new double[n] - 1;
	for (i = 1; i <= n; ++i)
		cin >> r[i];
	for (i = 1; i <= n; ++i)
		cin >> l[i];
	p = squr(l[n] + r[n], l[n]);
	s[n] = p.first;
	t[n] = p.second;
	for (i = n - 1; i >= 1; --i)
	{
		p = squr(l[i] + r[i] + s[i + 1] + t[i + 1], s[i + 1] * t[i + 1] + l[i]);
		s[i] = p.first;
		t[i] = p.second;
	}
	cout << setprecision(20) << setiosflags(ios::fixed);
	for (i = 1; i < n; ++i)
	if (s[i + 1] > s[i])
		cout << 0 << ' ';
	else
		cout << s[i] - s[i + 1] << ' ';
	cout << s[n] << endl;
	for (i = 1; i < n; ++i)
	if (t[i + 1] > t[i])
		cout << 0 << ' ';
	else
		cout << t[i] - t[i + 1] << ' ';
	cout << t[n];
	//system("pause");
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	unsigned long long n, m , a;
	cin >> n >> m >> a;

	unsigned long long row(n/a), col(m/a);
	if(n % a)
		row++;
	if(m % a)
		++col;
	cout << row * col << endl;
	
	return (0);
}
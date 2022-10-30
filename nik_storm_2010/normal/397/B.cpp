#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(true);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
    {
        long long x, l, r;
        cin >> x >> l >> r;
        long long z = x / l;
        if (z * l <= x && x <= z * r) cout << "Yes" << endl; else cout << "No" << endl;
    }
	return 0;
}
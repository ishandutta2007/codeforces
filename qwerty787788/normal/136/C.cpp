#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
long long n;
vector <long long> a;
long long ok = true;
//
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
        cin >> n;
        long long x;
        for (int i = 0; i < n; i++) {
                cin >> x;
                a.push_back(x);
                if (x != 1) ok = false;
        }
        sort(a.begin(), a.end());
        //
		if (n == 1 && a[0] == 1) {
			cout << "2" << endl;
			return 0;
		}
        cout << "1 ";
        for (int i = 0; i < a.size() - 1; i++)
                if (ok && i == a.size() - 2)
                        cout << 2 << endl; else
                        cout << a[i] << " ";
        //
}
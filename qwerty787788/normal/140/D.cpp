#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int a[100];
long long s, s1, s2;


int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //
        cin >> n;
        for (int i = 0; i < n; i++)
                cin >> a[i];
        //
        sort(a, a+n);
        for (int i = 0; i < n; i++) {
                if (s+a[i] <= 710) {
						if (s + a[i] > 350)
										  s2 += (s+a[i]-350);
                        s += a[i];
                        s1++;
                } else break;
        }
        cout << s1 << " " << s2;
        //
        return 0;
};
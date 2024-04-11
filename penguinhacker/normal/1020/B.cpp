#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n;
	cin >> n;

    int a[1000];
    for (int i=0; i<n; ++i) {
        int x;
        cin >> x;
        a[i] = x-1;
    }

    for (int i=0; i<n; ++i) {
        set<int> s;
        s.insert(i);
        bool check = true;
        int x = i;
        while (check == true) {
            check = false;
            if (s.find(a[x]) != s.end()) {
                cout << a[x]+1 << ' ';
                break;
            }
            else {
                check = true;
                s.insert(a[x]);
            }
            x = a[x];
        }
    }
	return 0;
}
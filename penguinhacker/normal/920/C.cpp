#include <bits/stdc++.h>
using namespace std;

#define ll long long

string k;
int n, a[200000], group[200000];

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    cin >> k;

    int num = 0;
    group[0] = num;
    for(int i = 1; i < n; ++i) {
        if (k[i-1] == '0') {
            num++;
        }
        group[i] = num;
    }

    for(int i = 0; i < n; ++i) {
        if (a[i] != i+1) {
            if (group[a[i]-1] != group[i]) {
                cout << "no";
                return 0;
            }
        }
    }

    cout << "yes";
    return 0;
}
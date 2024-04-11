#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
int a[101010];

void end(int x) {
    if (x == 1) cout << "sjfnb" << "\n";
    if (x == 2) cout << "cslnb" << "\n";
    exit(0);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    if (n == 1) {
        if (a[0]%2 == 0) end(2);
        else end(1);
    }
    int s = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] == a[i]) {
            if (a[i] == 0) end(2);
            a[i-1]--;
            s = 1;
            break;
        }
    }
    if (s) {
        for (int i = 1; i < n; i++) {
            if (a[i-1] == a[i]) end(2);
        }
    }
    ll u = s;
    for (int i = 0; i < n; i++) {
        u += a[i]-i;
    }
    if (u%2 == 0) end(2);
    else end(1);
}
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int n;
int a[202020];
int c;
ll t1, t2;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) if (a[i] == 0) c++;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) c--;
        else t1 += c;
    }
    for (int i = 0; i < n; i++) if (a[i] == 1) c++;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == 1) c--;
        else t2 += c;
    }
    cout << min(t1, t2) << endl;
}
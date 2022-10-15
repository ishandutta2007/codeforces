#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[1000005];

int n, k;
int a[400000];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i]]++;
    }
    for (int i = 1; i <= 1000000; i++) {
        p[i] += p[i-1];
    }
    int q = 0;
    for (int i = 1; i <= 1000000; i++) {
        int vy = -1;
        int s = 0;
        for (int j = i; j <= 1000000; j += i) {
             int x = j;
             int y = j+k;
             if (x <= vy) x = vy+1;
             if (y > 1000000) y = 1000000;
             vy = y;
             s += p[y]-p[x-1];
        }
        if (s == n) q = i;
    }
    cout << q << endl;
}
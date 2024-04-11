#include <iostream>
#include <algorithm>

using namespace std;

int d[100000];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        d[i%k] += a;
    }
    int v = d[0], t = 0;
    for (int i = 0; i < k; i++) {
        if (d[i] < v) {v = d[i]; t = i;}
    }
    cout << t+1 << endl;
}
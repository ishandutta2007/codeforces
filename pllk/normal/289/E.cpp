#include <iostream>

#define ll long long int

using namespace std;

int t[1000000];
ll v;
int n;

void haku(int k) {
    if (k <= 0) return;
    int d = 1;
    while (d*2 <= k) d *= 2;
    int a = (~k)&(d-1);
    int j = k;
    for (int i = a; i <= k; i++) {
        t[i] = j;
        t[j] = i;
        j--;
    }
    haku(a-1);
}

int main() {
    cin >> n;
    haku(n);
    for (int i = 0; i <= n; i++) {
        v += i^t[i];
    }
    cout << v << endl;
    for (int i = 0; i <= n; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
}
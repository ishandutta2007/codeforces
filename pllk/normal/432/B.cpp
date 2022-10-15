#include <iostream>

using namespace std;

int n;
int h[101010];
int a[101010];
int xh[101010];
int xa[101010];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> a[i];
        xh[h[i]]++;
        xa[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cout << n-1+xh[a[i]] << " " << n-1-xh[a[i]] << endl;
    }
}
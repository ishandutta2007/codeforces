#include <iostream>

using namespace std;

int x[5555];

int calc(int a, int b, int w) {
    if (a > b) return 0;
    int r = x[a];
    for (int i = a; i <= b; i++) r = min(r,x[i]);
    int k = a;
    int c1 = b-a+1;
    int c2 = r-w;
    for (int i = a; i <= b; i++) {
        if (x[i] == r) {
            c2 += calc(k,i-1,r);
            k = i+1;
        }
    }
    c2 += calc(k,b,r);
    return min(c1,c2);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    cout << calc(1,n,0) << "\n";
}
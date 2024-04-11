#include <iostream>

using namespace std;

int n, q;
string s;
int a[101010];
int b[101010];

int main() {
    cin >> n >> q;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i-1]-'a'+1;
        b[i] = b[i-1]+a[i];
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        cout << b[y]-b[x-1] << "\n";
    }
}
#include <iostream>

using namespace std;

int n;
string x[5050];
int a[5050], b[5050];
int u;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> a[i] >> b[i];
    for (int i = 1; i <= 366; i++) {
        int c1 = 0, c2 = 0;
        for (int j = 1; j <= n; j++) {
            if (b[j] < i || a[j] > i) continue;
            if (x[j] == "M") c1++;
            else c2++;
        }
        int c = min(c1,c2)*2;
        u = max(u,c);
    }
    cout << u << "\n";
}
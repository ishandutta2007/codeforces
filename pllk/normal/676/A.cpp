#include <iostream>

using namespace std;

int n;
int p[111];
int u;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            swap(p[i],p[j]);
            int p1, p2;
            for (int h = 1; h <= n; h++) {
                if (p[h] == 1) p1 = h;
                if (p[h] == n) p2 = h;
            }
            u = max(u,abs(p2-p1));
            swap(p[i],p[j]);
        }
    }
    cout << u << "\n";
}
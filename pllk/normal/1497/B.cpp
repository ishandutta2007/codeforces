#include <iostream>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int,int> c;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            c[x%m]++;
        }
        int r = 0;
        for (int i = 0; i < m; i++) {
            if (i == 0 || 2*i == m) {
                if (c[i]) r++;
            } else if (i < m-i) {
                int a = min(c[i],c[m-i]);
                int b = max(c[i],c[m-i]);
                if (a) r++;
                if (b > a) {
                    if (a) r += b-a-1;
                    else r += b-a;
                }
            }
        }
        cout << r << "\n";
    }
}
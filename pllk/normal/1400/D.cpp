#include <iostream>

using namespace std;

typedef long long ll;

int n;
int a[3030];
int ee[3030][3030][2];
ll dd[3030][3030][2];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            for (int x = 1; x <= n; x++) {
                ee[i][x][0] = 0;
                ee[i][x][1] = 0;
                dd[i][x][0] = 0;
                dd[i][x][1] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int x = 1; x <= n; x++) {
                dd[a[i]][x][1] += dd[x][a[i]][0];
                dd[a[i]][x][0] += ee[x][a[i]][1];
                ee[a[i]][x][1] += ee[x][x][0];
            }
            ee[a[i]][a[i]][0]++;
        }
        ll r = 0;
        for (int i = 1; i <= n; i++) {
            for (int x = 1; x <= n; x++) {
                r += dd[i][x][1];
            }
        }
        cout << r << "\n";
    }
}
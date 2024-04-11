#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, b[100], visited[200], a[200];
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> b[i];
        }
        for (int i=0; i<2*n; ++i) {
            visited[i] = 0;
        }
        bool pos = true;
        for (int i=0; i<n; ++i) {
            if (b[i] == 2*n) {
                pos = false;
                break;
            }
            visited[b[i]-1] = 1; a[2*i] = b[i];
            for (int j=b[i]+1; j<=2*n; ++j) {
                if (j == 2*n && visited[j-1]) {
                    pos = false;
                    break;
                }
                if (!visited[j-1]) {
                    bool pos1 = true;
                    for (int k=i+1; k<n; ++k) {
                        if (b[k] == j) {
                            pos1 = false;
                            break;
                        }
                    }
                    if (pos1) {
                        visited[j-1] = 1;
                        a[2*i+1] = j;
                        break;
                    }
                } 
            }
        }
        if (pos) {
            for (int i=0; i<2*n; ++i) {
                cout << a[i] << ' ';
            }
        }
        else {
            cout << -1;
        }
        cout << '\n';
    }
    return 0;
}
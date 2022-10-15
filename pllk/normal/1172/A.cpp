#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n;
int a[202020];
int b[202020];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    bool ok1 = true;
    for (int i = 0; i < n; i++) {
        if (b[i] != i+1) ok1 = false;
    }
    if (ok1) {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == 1) {
            int k = 1;
            bool ok2 = true;
            for (int j = i+1; j < n; j++) {
                k++;
                if (b[j] != k) {
                    ok2 = false;
                }
            }
            if (ok2) {
                vector<int> h(202020);
                deque<int> d;
                for (int i = 0; i < n; i++) {
                    h[a[i]]++;
                    d.push_back(b[i]);
                }
                for (int i = k+1; i <= n; i++) {
                    if (!h[i]) {ok2 = false; break;}
                    d.push_back(i);
                    h[i] = 0;
                    h[d[0]]++;
                    d.pop_front();
                }
                if (ok2) {
                    cout << n-k << "\n";
                    return 0;
                }
            }
        }
    }
    
    int u = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] != 0) u = max(u,i-b[i]+2);
    }
    cout << u+n << "\n";
}
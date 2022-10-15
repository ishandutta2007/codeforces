#include <iostream>
#include <algorithm>

using namespace std;

int n;
int h[202020];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> h[i];
        sort(h,h+n);
        int d = h[1]-h[0];
        for (int i = 0; i < n-1; i++) {
            d = min(d,h[i+1]-h[i]);
        }
        for (int i = 0; i < n-1; i++) {
            if (h[i+1]-h[i] == d) {
                cout << h[i] << " ";
                for (int j = i+2; j < n; j++) cout << h[j] << " ";
                for (int j = 0; j < i; j++) cout << h[j] << " ";
                cout << h[i+1] << "\n";
                break;
            }
        }
    }
}
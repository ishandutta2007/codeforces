#include <iostream>
#include <vector>

using namespace std;

int n;
int h[303030];
int p1[303030];
int p2[303030];
int d[303030];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector<int> v;
    v.clear();
    for (int i = n; i >= 1; i--) {
        while (v.size() && h[v.back()] <= h[i]) v.pop_back();
        if (v.size()) p1[i] = v.back();
        v.push_back(i);
    }
    v.clear();
    for (int i = n; i >= 1; i--) {
        while (v.size() && h[v.back()] >= h[i]) v.pop_back();
        if (v.size()) p2[i] = v.back();
        v.push_back(i);
    }
    d[n] = 0;
    for (int i = n-1; i >= 1; i--) {
        d[i] = d[i+1]+1;
        if (h[i] == h[i+1]) continue;
        if (h[i] > h[i+1]) {
            int k = i+1;
            while (k != 0) {
                d[i] = min(d[i],d[k]+1);
                if (h[k] >= h[i]) break;
                k = p1[k];
            }
        } else {
            int k = i+1;
            while (k != 0) {
                d[i] = min(d[i],d[k]+1);
                if (h[k] <= h[i]) break;
                k = p2[k];
            }
        }
    }
    cout << d[1] << "\n";
}
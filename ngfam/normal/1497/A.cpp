#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        map<int, int> a;
        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            a[x]++;
        }

        for(int i = 0; i < n; ++i) if (a[i] > 0) {
            a[i]--;
            cout << i << " ";
        }
        else break;

        for(auto p : a) while(a[p.first] > 0) { cout << p.first << " "; a[p.first]--; }
        cout << endl;
    }

    return 0;
}
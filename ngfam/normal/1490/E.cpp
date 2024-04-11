#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        vector<int> a(n), b; 
        for(int i = 0; i < n; ++i) cin >> a[i];
        b = a;

        sort(a.begin(), a.end());
        
        int cantwin = -1;
        long long sum = 0;
        for(int i = 0; i + 1 < n; ++i) {
            sum += a[i];
            if (sum < a[i + 1]) cantwin = max(cantwin, a[i]);
        }

        vector<int> winners;
        for(int i = 0; i < n; ++i) if (b[i] > cantwin) {
            winners.push_back(i);
        }

        cout << winners.size() << "\n";
        for(int x : winners) cout << x + 1 << " ";
        cout << endl;
    }

    return 0;
}
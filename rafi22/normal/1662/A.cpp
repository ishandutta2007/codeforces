#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define st first
#define nd second

int tab[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=1;i<=10;i++) {
            tab[i] = 0;
        }
        for(int i=0;i<n;i++) {
            int a, b;
            cin >> a >> b;
            tab[b] = max(tab[b], a);
        }
        int r = 0;
        bool ans = true;
        for(int i=1;i<=10;i++) {
            if(tab[i] == 0) {
                cout << "MOREPROBLEMS\n";
                ans = false;
                break;
            } else {
                r += tab[i];
            }
        }
        if(ans) cout << r << "\n";
    }
}
#include <bits/stdc++.h>

using namespace std;
int w;
long long n, s, jo;
long long sum;
vector<long long> sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s, jo=0, sum=0, sol.clear();
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            if (x<=s) {
                if (x>=(s+1)/2) jo=i;
                if (sum<(s+1)/2) sum+=x, sol.push_back(i);
            }
        }
        if (jo) {
            cout << 1 << "\n" << jo << "\n";
        } else if (sum>=(s+1)/2) {
            cout << sol.size() << "\n";
            for (int i:sol) cout << i << " ";
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
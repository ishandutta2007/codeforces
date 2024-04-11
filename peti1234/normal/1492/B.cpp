#include <bits/stdc++.h>

using namespace std;
int w, n, t[100002], maxi;
vector<int> pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, maxi=0;
        pos.clear();
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (t[i]>maxi) {
                maxi=t[i];
                pos.push_back(i);
            }
        }
        pos.push_back(n+1);
        int si=pos.size();
        for (int i=si-2; i>=0; i--) {
            for (int j=pos[i]; j<pos[i+1]; j++) {
                cout << t[j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
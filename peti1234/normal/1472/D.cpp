#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, t[c], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, sum=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1), reverse(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            if (i%2 && t[i]%2==0) {
                sum+=t[i];
            }
            if (i%2==0 && t[i]%2) {
                sum-=t[i];
            }
        }
        if (sum>0) cout << "Alice";
        if (sum<0) cout << "Bob";
        if (sum==0) cout << "Tie";
        cout << "\n";
    }
    return 0;
}
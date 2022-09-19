#include <bits/stdc++.h>

using namespace std;
int n;
int t[200001];
int mini=INT_MAX;
long long sum;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=n; i>=1; i--) {
       mini--;
       sum+=min(t[i], mini);
       mini=min(mini, t[i]);
       if (mini==0) {
            break;
       }
    }
    cout << sum << "\n";
    return 0;
}
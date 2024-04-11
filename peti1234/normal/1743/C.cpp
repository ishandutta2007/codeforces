#include <bits/stdc++.h>

using namespace std;
long long n, t[200005], sum;
string s;
void solve() {
    sum=0;
    cin >> n >> s;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=0; i<n; i++) {
        if (s[i]=='1' && (i==0 || s[i-1]=='0')) {
            long long mini=t[i];
            sum+=t[i];
            for (int j=i; j<n; j++) {
                if (s[j]=='1') {
                    sum+=t[j+1];
                    mini=min(mini, t[j+1]);
                } else {
                    break;
                }
            }
            sum-=mini;
        }
    }
    cout << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
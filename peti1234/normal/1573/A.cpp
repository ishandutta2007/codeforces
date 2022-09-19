#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, n;
    string s;
    cin >> w;
    while (w--) {
        cin >> n >> s;
        int sum=0;
        for (int i=0; i<n; i++) {
            sum+=(s[i]-'0');
            if (i<n-1 && s[i]!='0') {
                sum++;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
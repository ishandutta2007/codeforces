#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        int n;
        string s;
        cin >> n >> s;
        long long sum=n;
        for (int i=0; i<n; i++) {
            if (i==0 || s[i]!=s[i-1]) {
                sum+=i;
            }
        }
        //cout << "valasz.......... ";
        cout << sum << "\n";
    }
    return 0;
}
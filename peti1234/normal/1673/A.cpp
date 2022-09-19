#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        int n=s.size(), sum=0;
        for (int i=0; i<n; i++) {
            sum+=(s[i]-'a'+1);
        }
        if (n%2==1) {
            sum-=2*min(s[0]-'a'+1, s[n-1]-'a'+1);
        }
        if (sum>0) {
            cout << "Alice " << sum << "\n";
        } else {
            cout << "Bob " << -sum << "\n";
        }
    }
    return 0;
}
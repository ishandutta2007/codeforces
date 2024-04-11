#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[5];
    for(int j = 1;j<=4;j++){
        cin >> a[j];
    }
    string s;
    cin >> s;
    int ans = 0;
    for(int j = 0;j<s.size();j++){
        ans += a[s[j]-48];
    }
    cout << ans;

    return 0;
}
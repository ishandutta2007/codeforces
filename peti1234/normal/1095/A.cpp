#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, cnt=0;
    string s;
    cin >> n >> s;
    for (int i=1; cnt<n; i++) {
        cout << s[cnt];
        cnt+=i;
    }
    return 0;
}
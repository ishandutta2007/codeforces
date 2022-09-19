#include <bits/stdc++.h>

using namespace std;
int n, k;
string s;
int main()
{
    cin >> n >> k >> s;
    if (n==1 && k) {
        s[0]='0';
        k=0;
    }
    for (int i=0; i<n; i++) {
        if (k) {
            if (i==0 && s[i]!='1') s[i]='1', k--;
            if (i>0 && s[i]!='0') s[i]='0', k--;
        }
    }
    cout << s << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int p;
int main()
{
    cin >> s;
    p=s.size()-1;
    for (int i=0; i<p; i++) {
        if (s[i]=='V' && s[i+1]=='K') {
            n++;
        }
    }
    if ((s[0]=='K' && s[1]=='K') || (s[p-1]=='V' && s[p]=='V')) {
        n++;
        cout <<  n << endl;
        return 0;
    }
    for (int i=0; i<=p-2; i++) {
        if (s[i]==s[i+1] && s[i]==s[i+2]) {
            n++;
            cout << n << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
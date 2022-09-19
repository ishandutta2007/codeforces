#include <bits/stdc++.h>
 
using namespace std;
string s;
int main()
{
    cin >> s;
    int si=s.size();
    for (int i=1; i<s.size(); i++) {
        if (s[i]=='1') {
            cout << (si+1)/2;
            return 0;
        }
    }
    cout << si/2 << endl;
    return 0;
}
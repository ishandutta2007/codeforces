#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int main()
{
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='1') {
            for (int j=i; j<s.size(); j++) {
                if (s[j]=='0') {
                    n++;
                }
            }
            if (n>=6) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}
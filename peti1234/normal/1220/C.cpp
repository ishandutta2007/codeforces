#include <bits/stdc++.h>
 
using namespace std;
int mini=100;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        int x=s[i]-'a';
        if (x<=mini) {
            cout << "Mike" << "\n";
        } else {
            cout << "Ann" << "\n";
        }
        mini=min(mini, x);
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int n;
int k=0;
string s;
int main()
{
    cin >> n;
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='8') {
            k++;
        }
    }
    cout << min(k, n/11) << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int main()
{
    cin >> n;
    cin >> s;
    for (int i=1; i<s.size(); i++) {
        int a=s[i]-'a';
        int b=s[i-1]-'a';
        if (a<b) {
            cout << "YES" << endl << i << " " << i+1 << endl;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
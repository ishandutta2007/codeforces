#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int n, e=0, db=0, o=0;
        string s;
        cin >> n >> s;
        for (int i=0; i<s.size(); i++) db+=(s[i]=='0');
        for (int i=0; i<n; i++) {
            char c=s[i];
            if (c=='1') e++;
            else db--, o++;
            if ((c=='1' && !db) || (c=='0' && (e<1 || db==0))) cout << c;
        }
        cout << "\n";
    }
    return 0;
}
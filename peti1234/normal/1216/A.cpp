#include <bits/stdc++.h>

using namespace std;
string s;
int db, n;
int main()
{
    cin >> n >> s;
    for (int i=0; i<n; i+=2) {
        if (s[i]==s[i+1]) {
            db++;
            s[i]=(s[i]=='a' ? 'b' : 'a');
        }
    }
    cout << db << "\n" << s << "\n";
    return 0;
}
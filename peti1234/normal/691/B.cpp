#include <bits/stdc++.h>

using namespace std;
int n, baj;
string s;
vector<char> sz={'A', 'H', 'I', 'M', 'O', 'o', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y'};
char mir(char c) {
    for (auto p:sz) {
        if (c==p) return c;
    }
    if (c=='b') return 'd';
    if (c=='d') return 'b';
    if (c=='p') return 'q';
    if (c=='q') return 'p';
    return '.';
}
int main()
{
    cin >> s;
    n=s.size();
    for (int i=0; i<n; i++) {
        if (mir(s[i])!=s[n-i-1]) {
            baj=1;
        }
    }
    cout << (!baj ? "TAK" : "NIE") << "\n";
    return 0;
}
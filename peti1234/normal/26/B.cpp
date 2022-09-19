#include <bits/stdc++.h>

using namespace std;
string s;
int db, k;
int main()
{
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='(') db++, k++;
        else if (k) db++, k--;
    }
    cout << db-k << endl;
    return 0;
}
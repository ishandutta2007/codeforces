#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int db=(s[0]=='a')+(s[0]=='h')+(s[1]=='1')+(s[1]=='8');
    cout << (db==0 ? 8 : db==1 ? 5 : 3) << "\n";
    return 0;
}
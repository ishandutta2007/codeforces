#include <bits/stdc++.h>

using namespace std;
string s;
int si, x, cnt, mul=1;
void solve(char a, char b) {
    char x=s[si-2], y=s[si-1];
    if (x!='_' && x!='X' && x!=a || y!='_' && y!='X' && y!=b || x=='X' && y=='X' && a!=b || x=='X' && s[0]=='X' && a=='0' || y=='X' && s[0]=='X' && b=='0' || si==2 && a=='0') return;
    cnt++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    if (s.size()==1) {
        if (s[0]=='_' || s[0]=='X' || s[0]=='0') cout << 1 << "\n";
        else cout << 0 << "\n";
        return 0;
    }
    if (s[0]=='0') {
        cout << 0 << "\n";
        return 0;
    }
    si=s.size();
    for (int i=0; i<si-2; i++) {
        if (s[i]=='_') {
            if (i==0) mul*=9;
            else mul*=10;
        }
        if (s[i]=='X') x=1;
    }
    if (s[si-2]=='X' || s[si-1]=='X') x=0;
    if (x) {
        if (s[0]=='X') mul*=9;
        else mul*=10;
    }
    solve('0', '0'), solve('2', '5'), solve('5', '0'), solve('7', '5');
    cout << cnt*mul << "\n";
    return 0;
}
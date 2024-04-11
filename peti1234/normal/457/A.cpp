#include <bits/stdc++.h>

using namespace std;
string x, y, a, b;
int sa, sb;
string solve(string s) {
    int si=s.size();
    for (int i=1; i<si-1; i++) {
        if (s[i]=='1' && s[i+1]=='1') {
            s[i]=s[i+1]='0';
            s[i-1]='1';
            i=max(0, i-3);
        }
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    x=y="0";
    cin >> a >> b;
    sa=a.size(), sb=b.size();
    for (int i=0; i<sb; i++) {
        x+="0";
    }
    for (int i=0; i<sa; i++) {
        y+="0";
    }
    x+=a, y+=b;
    x=solve(x), y=solve(y);
    if (x>y) {
        cout << ">";
    }
    if (y>x) {
        cout << "<";
    }
    if (x==y) {
        cout << "=";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
string s;
int n, x, db, el, jel;
int out()
{
    for (int i=0; i<s.size(); i++) cout << s[i];
    cout.flush() << "\n";
    int a;
    cin >> a;
    return a;
}
int main()
{
    s+='a';
    x=out();
    if (x==300) {
        for (int i=0; i<x; i++) cout << 'b';
        cout << "\n";
        return 0;
    }
    n=x+1;
    s[0]='a';
    for (int i=1; i<=x; i++) s+='a';
    db=out(), el=db;
    if (!db) return 0;
    if (db>x) {
        for (int i=0; i<x; i++) cout << 'b';
        cout << "\n";
        return 0;
    }
    for (int i=0; i<n-1; i++) {
        s[i]='b';
        jel=out();
        if (jel>el) s[i]='a';
        else db--, el=jel;
    }
    if (db) s.back()='b';
    out();
    return 0;
}
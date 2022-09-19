#include <bits/stdc++.h>

using namespace std;
bool jo(string a, string b) {
    int sa=a.size(), sb=b.size();
    for (int i=0; i+sa<=sb; i++) {
        if (a==b.substr(i, sa)) {
            bool jo=1;
            for (int j=0; j<i; j++) {
                if (b[j]=='0') jo=0;
            }
            for (int j=i+sa; j<sb; j++) if (b[j]=='0') jo=0;
            if (jo) {
                return true;
            }
        }
    }
    return false;
}
bool solve(long long a, long long b) {
    string aa, bb;
    while (a) {
        aa+=(a%2 ? "1" : "0");
        a/=2;
    }
    while (b) {
        bb+=(b%2 ? "1" : "0");
        b/=2;
    }
    if (jo(aa, bb)) {
        return true;
    }
    reverse(aa.begin(), aa.end());
    if (jo(aa, bb)) {
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long a, b;
    cin >> a >> b;
    if (a==b) {
        cout << "YES\n";
        return 0;
    }
    if (solve(2*a+1, b)) {
        cout << "YES\n";
        return 0;
    }
    while (a%2==0) {
        a/=2;
    }
    if (solve(a, b)) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}
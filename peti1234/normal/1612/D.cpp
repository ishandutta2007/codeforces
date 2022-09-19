#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, a, b, x;
    cin >> w;
    while (w--) {
        cin >> a >> b >> x;
        while (true) {
            if (a<b) swap(a, b);
            if (b==0 || a<x) {
                cout << "NO\n";
                break;
            }
            if (b<=x && a%b==x%b) {
                cout << "YES\n";
                break;
            }
            a=a%b;
        }
    }
    return 0;
}
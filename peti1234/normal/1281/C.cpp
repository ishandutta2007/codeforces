#include <bits/stdc++.h>

using namespace std;
long long w, n, si, pos, mod=1e9+7;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> a;
        si=a.size(), pos=0;
        while (si<n) {
            while (a[pos]=='1') {
                pos++;
            }
            b=a.substr(pos+1, si-pos-1);
            int db=a[pos]-'1';
            for (int i=1; i<=db; i++) {
                a+=b;
            }
            pos++;
            si=a.size();
        }
        while (pos<n) {
            long long db=a[pos]-'1', pl=si-pos-1+mod;
            si+=db*pl;
            si%=mod;
            pos++;
        }
        //cout << "valasz: ";
        cout << si << "\n";
    }
    return 0;
}
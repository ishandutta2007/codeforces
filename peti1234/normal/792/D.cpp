#include <bits/stdc++.h>

using namespace std;
long long n, q, e=1;
long long ert(long long x) {
    return (e<<__builtin_ctzll(x));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    n++;
    while (q--) {
        long long pos;
        string s;
        cin >> pos >> s;
        for (auto p:s) {
            long long k=ert(pos);
            if (p=='U') {
                if (2*pos==n) continue;
                if ((pos+k)%(4*k)) pos+=k;
                else pos-=k;
            } else {
                if (pos%2) continue;
                k/=2;
                if (p=='L') pos-=k;
                else pos+=k;
            }
        }
        cout << pos << "\n";
    }
    return 0;
}
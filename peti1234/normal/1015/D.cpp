#include <bits/stdc++.h>

using namespace std;
long long n, k, s, pos=1, e=1;
int main()
{
    cin >> n >> k >> s;
    if (k*(n-1)<s || k>s) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        while (k>0) {
            if (k==s) {
                if (pos>1) {
                    cout << --pos << " ";
                    k--, s--;
                } else {
                    cout << ++pos << " ";
                    k--, s--;
                }
            } else {
                if (pos==1) {
                    long long kov=min(n, pos+s-k+1);
                    cout << kov << " ";
                    k--, s-=kov-pos;
                    pos=kov;
                } else {
                    long long kov=max(e, pos-(s-k+1));
                    cout << kov << " ";
                    k--, s-=pos-kov;
                    pos=kov;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
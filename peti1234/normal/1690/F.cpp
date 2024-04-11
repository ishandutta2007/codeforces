#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, p[c], ans;
bool v[c];
string s, k;
void solve(int a) {
    //cout << "solve " << a << "\n";
    v[a]=true;
    k+=s[a-1];
    if (!v[p[a]]) {
        solve(p[a]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        ans=1;
        cin >> s;
        for (int i=1; i<=n; i++) {
            cin >> p[i];
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                solve(i);
                long long si=k.size();
                //cout << "fontos " << k << "\n";
                for (long long j=1; j<=si; j++) {
                    if (si%j==0) {
                        bool jo=1;
                        for (int f=0; f<si; f++) {
                            if (k[f]!=k[(f+j)%si]) {
                                jo=0;
                            }
                        }
                        if (jo) {
                            ans=ans*j/__gcd(ans, j);
                            break;
                        }
                    }
                }
                k.clear();
            }
        }
        for (int i=1; i<=n; i++) {
            v[i]=0;
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
1
5
ababa
3 4 5 2 1
*/
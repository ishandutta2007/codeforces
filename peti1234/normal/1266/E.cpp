#include <bits/stdc++.h>

using namespace std;
map<long long, long long> p[200003];
long long t[200003], sum;
long long n, q;
void torol(long long a)
{
    t[a]++;
    if (t[a]>0) sum++;
}
void ad(long long a)
{
    t[a]--;
    if (t[a]>=0) sum--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i=1; i<=n; i++) cin >> t[i], sum+=t[i];
    cin >> q;
    for (long long i=1; i<=q; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        auto x=p[a].find(b);
        if (x!=p[a].end()) {
            torol(p[a][b]);
        }
        p[a][b]=c, ad(c);
        cout << sum << "\n";
    }
    return 0;
}
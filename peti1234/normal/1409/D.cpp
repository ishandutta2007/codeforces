#include <bits/stdc++.h>

using namespace std;
long long w, n, ans, s, x, po=1;
int db(long long p) {
    int k=0;
    while(p) k+=p%10, p/=10;
    return k;
}
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> s, ans=0, po=1;
        while(db(n)>s) {
            x=(10-n%10);
            n+=x, ans+=x*po, po*=10, n/=10;
        }
        cout << ans << "\n";
    }
    return 0;
}
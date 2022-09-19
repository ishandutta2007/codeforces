#include <bits/stdc++.h>

using namespace std;
int w, n, a, b, c, d, p, q, r, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> a >> b >> c >> d;
        p=n*(a-b), q=n*(a+b), r=c-d, s=c+d;
        if (min(q, s)>=max(p, r)) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
    return 0;
}
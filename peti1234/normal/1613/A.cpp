#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, a, b, c, d;
    cin >> w;
    while (w--) {
        cin >> a >> b >> c >> d;
        int s=min(b, d);
        b-=s, d-=s;
        if (b>10) cout << ">" << "\n";
        else if (d>10) cout << "<" << "\n";
        else {
            while (b) a*=10, b--;
            while (d) c*=10, d--;
            cout << (a>c ? ">" : a<c ? "<" : "=") << "\n";
        }
    }
    return 0;
}
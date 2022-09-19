#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        int a, b, c, db=0;
        cin >> a >> b >> c;
        if (a) db++, a--;
        if (b) db++, b--;
        if (c) db++, c--;
        if (a>=2) {
            if (b) a--, b--, db++;
            if (c) a--, c--, db++;
            if (b && c) b--, c--, db++;
        } else {
            if (b && c) b--, c--, db++;
            if (a && b) a--, b--, db++;
            if (a && c) a--, c--, db++;
        }
        if (a && b && c) db++;
        cout << db << "\n";
    }
    return 0;
}
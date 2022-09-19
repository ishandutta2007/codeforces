#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        for (int i=0; i<c; i++) v[i]=0;
        int a, b, db=0;; cin >> a >> b;
        for (int i=0; i<a+b; i++) {
            int x; cin >> x;
            if (v[x]) db++;
            v[x]=1;
        }
        cout << db << "\n";
    }
    return 0;
}
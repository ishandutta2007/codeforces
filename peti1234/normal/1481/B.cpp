#include <bits/stdc++.h>

using namespace std;
int w, n, k, t[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        t[n+1]=0, t[n+2]=1;
        int pos=0;
        while (k--) {
            for (pos=1; t[pos]>=t[pos+1]; pos++) {

            }
            t[pos]++;
            if (pos==n+1) {
                break;
            }
        }
        if (pos==n+1) {
            pos=-1;
        }
        //cout << "valasz " << pos << endl;
        cout << pos << "\n";
    }
    return 0;
}
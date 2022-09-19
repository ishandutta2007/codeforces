#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, bal, jobb, cnt, kb[c], kj[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        char c;
        int x;
        cin >> c >> x;
        if (c=='L') {
            bal++;
            kb[x]=-bal;
            kj[x]=cnt-jobb;
            cnt++;
        }
        if (c=='R') {
            jobb++;
            kj[x]=-jobb;
            kb[x]=cnt-bal;
            cnt++;
        }
        if (c=='?') {
            cout << min(bal+kb[x], jobb+kj[x]) << "\n";
        }
    }
    return 0;
}
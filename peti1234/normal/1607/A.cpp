#include <bits/stdc++.h>

using namespace std;
string a, b;
int w, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        ans=0;
        int si=b.size();
        for (int i=0; i<si-1; i++) {
            int x=0, y=0;
            for (int j=0; j<a.size(); j++) {
                if (a[j]==b[i]) x=j;
                if (a[j]==b[i+1]) y=j;
            }
            ans+=abs(x-y);
        }
        cout << ans << "\n";
    }
    return 0;
}
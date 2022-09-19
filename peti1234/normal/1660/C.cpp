#include <bits/stdc++.h>

using namespace std;
int w, ut[27];
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> s;
        int ans=0, cnt=0;
        for (auto c:s) {
            cnt++;
            int x=c-'a';
            if (ut[x]) {
                ut[x]=0;
                for (int i=0; i<27; i++) {
                    if (ut[i]) {
                        ans++;
                        ut[i]=0;
                    }
                }
            } else {
                ut[x]=cnt;
            }
        }
        for (int i=0; i<27; i++) {
            if (ut[i]) {
                ans++;
                ut[i]=0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
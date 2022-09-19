#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s; cin >> s;
        int n=s.size(), cnt=0, mini=0, jo=0;
        for (int i=0; i<8; i++) {
            int cnt=0, mini=0;
            for (int j=0; j<n; j++) {
                int ert=(s[j]-'A');
                if (i & (1<<ert)) {
                    cnt++;
                } else {
                    cnt--;
                    mini=min(mini, cnt);
                }
            }
            if (!cnt && mini==0) {
                jo=1;
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}
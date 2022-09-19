#include <bits/stdc++.h>

using namespace std;
int n, m, ans;
int main() {
    cin >> n >> m;
    vector<string> s(n);
    vector<int> kell(m, 0), pr_fel(n, -1);
    int pr_s=-1, pr_k=-1;
    for (int i=n-1; i>=0; i--) {
        cin >> s[i];
    }
    for (int i=0; i<m; i++) {
        cin >> kell[i];
    }
    for (int j=0; j<m; j++) {
        vector<int> fel(n, -1);
        int maxi=-1, cnt=0, cel=-1;
        for (int i=0; i<n; i++) {
            if (s[i][j]=='#') {
                maxi=i;
                cnt++;
                fel[i]=i;
                if (cnt==kell[j]) {
                    cel=i;
                }
            }
            if (i) {
                fel[i]=max(fel[i], fel[i-1]);
            }
        }
        for (int i=n-2; i>=0; i--) {
            if (s[i][j]=='#') {
                fel[i]=max(fel[i], fel[i+1]);
                if (pr_fel[i]!=-1) {
                    fel[i]=max(fel[i], fel[pr_fel[i]]);
                }
            }
        }
        for (int i=1; i<n; i++) {
            fel[i]=max(fel[i-1], fel[i]);
        }
        if (pr_k>maxi) {
            ans++;
            pr_s=maxi, pr_k=-1;
            pr_fel=fel;
            continue;
        } else {
            cel=max(cel, pr_k);
            if (cel!=-1) {
                while (s[cel][j]!='#') {
                    cel++;
                }
                for (int i=0; i<n; i++) {
                    if (fel[i]>=cel) {
                        cel=i;
                        break;
                    }
                }
            }
            pr_s=(pr_s==-1 ? -1 : fel[pr_s]);
            pr_k=(cel>pr_s ? cel : -1);
            pr_fel=fel;

        }
    }
    if (pr_k!=-1) {
        ans++;
    }
    cout << ans << "\n";
	return 0;
}
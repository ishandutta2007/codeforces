#include <bits/stdc++.h>

using namespace std;
int w, n;
string a, b;
bool v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int tc=1; tc<=w; tc++) {
        cin >> n;
        cin >> a >> b;
        long long mini=1e10, ert=0;
        int pos, cnt;
        for (int i=0; i<n; i++) {
            if (i==0 || b[i]!=b[i-1]) {
                int fc=-1;
                pos=-1, cnt=0;
                for (int j=0; j<n; j++) {
                    if (v[j]) continue;
                    if (a[j]<b[i]) {
                        mini=min(mini, ert+cnt);
                    }
                    if (a[j]==b[i] && pos==-1) {
                        pos=j;
                        v[pos]=1;
                        fc=cnt;
                    }
                    cnt++;
                }
                if (fc==-1) {
                    break;
                }
                ert+=fc;
                cnt=fc;
            } else {
                int cnt2=cnt;
                while (pos<n) {
                    if (v[pos]) {
                        pos++;
                        continue;
                    }
                    if (a[pos]>b[i]) cnt++;
                    if (a[pos]==b[i]) {
                        if (cnt2==0 && (cnt>0 || i+1<n && b[i]!=b[i+1])) {
                            int pos2=pos, cnt3=cnt;
                            while (pos2<n) {
                                if (v[pos2]) {
                                    pos2++;
                                    continue;
                                }
                                if (a[pos2]<b[i]) {
                                    mini=min(mini, ert+cnt3);
                                }
                                cnt3++;
                                pos2++;
                            }
                        }
                        ert+=cnt;
                        v[pos]=1;
                        break;
                    }
                    if (a[pos]<b[i]) {
                        mini=min(mini, ert+cnt);
                        ert+=cnt;
                        break;
                    }
                    pos++;
                }
                if (pos==n) {
                    break;
                }
            }
            if (i>0 && b[i]<b[i-1]) {
                mini=min(mini, ert+1);
            }
            if (ert>=mini) {
                break;
            }
        }
        if (mini==1e10) mini=-1;
        cout << mini << "\n";
        for (int i=0; i<=n; i++) {
            v[i]=0;
        }
    }
    return 0;
}
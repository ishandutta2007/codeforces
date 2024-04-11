#include <bits/stdc++.h>

using namespace std;
const int c=260;
int w, n, m, e[c][c], t[c][c], l[c], ans[c], cnt;
bool baj;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            e[a][b]=e[b][a]=i;
            if (c!=-1) {
                cnt++;
                t[cnt][i]=1, t[cnt][0]=c;
                l[i]=cnt;
            }
        }
        for (int a=1; a<=n; a++) {
            for (int b=a+1; b<=n; b++) {
                for (int c=b+1; c<=n; c++) {
                    if (e[a][b] && e[b][c] && e[c][a]) {
                        cnt++;
                        t[cnt][e[a][b]]=1, t[cnt][e[b][c]]=1, t[cnt][e[c][a]]=1;
                        int pos=m;
                        while (pos>0 && (!t[cnt][pos] || l[pos])) {
                            if (!t[cnt][pos]) {
                                pos--;
                                continue;
                            }
                            int k=l[pos], p=3-t[cnt][pos];
                            for (int i=0; i<=pos; i++) {
                                t[cnt][i]=(t[cnt][i]+p*t[k][i])%3;
                            }
                            pos--;
                        }
                        if (pos>0) {
                            l[pos]=cnt;
                            if (t[cnt][pos]==2) {
                                for (int i=0; i<=pos; i++) {
                                    t[cnt][i]=2*t[cnt][i]%3;
                                }
                            }
                        } else {
                            if (t[cnt][pos]) {
                                baj=1;
                            } else {
                                cnt--;
                            }
                        }
                    }
                }
            }
        }
        if (baj) {
            cout << -1 << "\n";
        } else {

            for (int i=1; i<=m; i++) {
                int pos=l[i];
                if (!pos) {
                    ans[i]=1;
                } else {
                    int sum=3-t[pos][0];
                    for (int j=1; j<i; j++) {
                        sum+=t[pos][j]*ans[j];
                    }
                    sum=(3-sum%3)%3;
                    ans[i]=(sum==0 ? 3 : t[pos][i]==sum ? 1 : 2);
                }
                cout << ans[i] << " ";
            }
            cout << "\n";
        }

        for (int i=0; i<=m; i++) {
            l[i]=0, ans[i]=0;
            for (int j=0; j<=m; j++) {
                e[i][j]=0, t[i][j]=0;
            }
        }
        baj=0, cnt=0;
    }
    return 0;
}
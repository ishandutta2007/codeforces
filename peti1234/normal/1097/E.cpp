#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, cel, t[c], val[c][2], fel[c][2], hely[c][2], db[2], cnt, si;
bool v[c];
vector<int> ans[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cel=sqrt(2*n);
        if (cel*cel+cel>2*n) {
            cel--;
        }
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        while (cnt<n) {
            for (int j=0; j<2; j++) {
                db[j]=0;
                for (int i=1; i<=n; i++) {
                    val[i][j]=fel[i][j]=hely[i][j]=0;
                }
            }
            for (int i=1; i<=n; i++) {
                if (v[i]) {
                    continue;
                }
                for (int id=0; id<2; id++) {
                    int lo=0, hi=db[id]+1, mid;
                    while (hi-lo>1) {
                        mid=(hi+lo)/2;
                        if ((id) == (t[i]>t[val[mid][id]])) {
                            hi=mid;
                        } else {
                            lo=mid;
                        }
                    }
                    val[hi][id]=i, hely[i][id]=hi;
                    fel[i][id]=val[hi-1][id];
                    db[id]=max(db[id], hi);
                }
            }
            bool h=(db[0]<db[1]);
            if (db[!h]<=cel) {
                //cout << "fontos\n";
                h=!h;
                for (int i=1; i<=n; i++) {
                    if (!v[i]) {
                        ans[si+hely[i][h]].push_back(t[i]);
                    }
                }
                si+=db[h];
                break;
            } else {
                int pos=val[db[h]][h];
                si++;
                cnt+=db[h];
                while (pos) {
                    ans[si].push_back(t[pos]);
                    v[pos]=1;
                    pos=fel[pos][h];
                }
                reverse(ans[si].begin(), ans[si].end());
                cel--;
            }
        }
        cout << si << "\n";
        for (int i=1; i<=si; i++) {
            cout << ans[i].size() << " ";
            for (auto x:ans[i]) {
                cout << x << " ";
            }
            cout << "\n";
        }
        for (int i=1; i<=n; i++) {
            v[i]=0;
            ans[i].clear();
        }
        cnt=0, si=0;
    }
    return 0;
}
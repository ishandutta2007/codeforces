#include <bits/stdc++.h>

using namespace std;
const int c=200002, gy=402;
int t[c], db[c], n, pos, maxi;
int esz[c], hsz[c];
int ert[c], ossz[c], maxh, mpos, bsz;
void add(int a, int k) {
    if (a==pos) {
        mpos+=k;
    } else {
        ossz[ert[a]]--;
        ert[a]+=k;
        ossz[ert[a]]++;
        if (!ossz[maxh]) maxh--;
        maxh=max(maxh, ert[a]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        db[t[i]]++;
    }
    for (int i=1; i<=n; i++) {
        if (db[t[i]]>db[pos]) pos=t[i];
    }
    for (int i=1; i<=gy; i++) {
        for (int j=1; j<=n; j++) ert[j]=0, ossz[j]=0;
        ossz[0]=n;
        maxh=0, mpos=0, bsz=0;
        for (int j=1; j<=n; j++) {
            add(t[j], 1);
            while(mpos>i) {
                bsz++;
                add(t[bsz], -1);
            }
            if (maxh>=i) {
                maxi=max(maxi, j-bsz);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        if (i!=pos && db[i]>=gy) {
            int cnt=0, emax=0, hmax=0, dif=db[pos]-db[i];
            for (int j=1; j<=n; j++) {
                if (t[j]==pos) cnt++;
                if (t[j]==i) cnt--;
                if (cnt>emax) {
                    emax++;
                    esz[emax]=j;
                }
            }
            cnt=0;
            for (int j=n; j>=1; j--) {
                if (t[j]==pos) cnt++;
                if (t[j]==i) cnt--;
                if (cnt>hmax) {
                    hmax++;
                    hsz[hmax]=n-j+1;
                }
            }
            for (int j=0; j<=dif; j++) {
                if (j<=emax && dif-j<=hmax) {
                    maxi=max(maxi, n-esz[j]-hsz[dif-j]);
                }
            }
        }
    }

    cout << maxi << "\n";
    return 0;
}
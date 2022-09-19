#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, ert[c], ans[c], mini, mindb, maxi, dif;
int kerd(int a, int b, int c) {
    cout.flush() << "? " << a << " " << b << " " << c << "\n";
    int x;
    cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        mini=c, maxi=0, mindb=0;
        for (int i=3; i<=n; i++) {
            ert[i]=kerd(1, 2, i);
            maxi=max(maxi, ert[i]);
            if (ert[i]<mini) {
                mini=ert[i];
                mindb=0;
            }
            if (ert[i]==mini) {
                mindb++;
            }
        }
        if (mindb==1) {
            dif=2*mini;
        } else {
            dif=2*mini-1;
        }
        if (dif>5) {
            vector<int> spec[2];
            int pos=0, pos2;
            for (int i=3; i<=n; i++) {
                if (dif-ert[i]==1) {
                    spec[0].push_back(i);
                }
                if (dif-ert[i]==2) {
                    spec[1].push_back(i);
                }
            }
            for (int a:spec[0]) {
                for (int b:spec[1]) {
                    if (kerd(1, a, b)==1) {
                        pos=a, pos2=b;
                    }
                }
            }
            int kis=0;
            ans[1]=0, ans[2]=dif, ans[pos]=1;
            for (int i=3; i<=n; i++) {
                if (i!=pos) {
                    int x=kerd(1, pos, i);
                    if (ert[i]<dif) {
                        ans[i]=x+1;
                    } else {
                        if (x<dif) {
                            ans[i]=-x;
                        }
                        if (x==dif) {
                            int y=kerd(pos, pos2, i);
                            if (y==x+1) {
                                ans[i]=-x;
                            } else {
                                ans[i]=x+1;
                            }
                        }
                        if (x>dif) {
                            if (x==ert[i]) {
                                ans[i]=-x;
                            } else {
                                ans[i]=x+1;
                            }
                        }
                    }
                    kis=min(kis, ans[i]);
                }
            }
            kis=-kis+1;
            for (int i=1; i<=n; i++) {
                ans[i]+=kis;
            }
        } else {
            vector<int> spec[3];
            for (int i=3; i<=n; i++) {
                int kul=maxi-ert[i];
                if (kul<=2) {
                    spec[kul].push_back(i);
                }
            }
            int pos=0, pos2=0;
            for (int a:spec[0]) {
                for (int b:spec[1]) {
                    for (int c:spec[2]) {
                        int x=kerd(a, b, c);
                        if (x==1) {
                            pos=a, pos2=b;
                        }
                    }
                }
            }
            ans[pos]=1, ans[pos2]=2;
            for (int i=1; i<=n; i++) {
                if (i!=pos && i!=pos2) {
                    ans[i]=kerd(pos, pos2, i)+2;
                }
            }
            if (ans[1]>ans[2]) {
                for (int i=1; i<=n; i++) {
                    ans[i]=n+1-ans[i];
                }
            }
        }
        cout << "! ";
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout.flush() << "\n";
        int x;
        cin >> x;
    }
    return 0;
}
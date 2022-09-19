#include <bits/stdc++.h>

using namespace std;
const int c=300005, p=20;
long long n, m, k, t[c], t2[c], kov[c], fel[c][p], ar[c][p];
deque<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        while (q.size()>0 && t[i]<=t[q.back()]) q.pop_back();
        q.push_back(i);
        if (i-q.front()>=k) q.pop_front();
        t2[i]=t[q.front()];
    }
    for (int i=0; i<p; i++) {
        fel[n+1][i]=n+1;
        kov[n+1]=n+1;
    }
    for (int i=n; i>=1; i--) {
        kov[i]=fel[i][0]=min(i+k, n+1);
        while (t[i]<=t2[kov[i]]) {
            kov[i]=kov[kov[i]];
        }
        while (t2[i]<=t2[fel[i][0]]) {
            fel[i][0]=fel[fel[i][0]][0];
        }
        ar[i][0]=(fel[i][0]-i+k-1)/k*t2[i];
    }
    for (int j=1; j<p; j++) {
        for (int i=1; i<=n; i++) {
            int s=fel[i][j-1];
            fel[i][j]=fel[s][j-1];
            ar[i][j]=ar[i][j-1]+ar[s][j-1];
        }
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (kov[l]>r) {
            cout << ((r-l)/k+1)*t[l] << "\n";
        } else {
            long long ans=(kov[l]-l)/k*t[l];
            l=kov[l];
            for (int j=p-1; j>=0; j--) {
                if (fel[l][j]<=r) {
                    ans+=ar[l][j];
                    l=fel[l][j];
                }
            }
            ans+=((r-l)/k+1)*t2[l];
            cout << ans << "\n";
        }
    }
    return 0;
}
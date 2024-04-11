#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, xx, yy, a[c], b[c], sdb[c], odb[c];
bool jo(int ert) {
    long long maxi=0, maxi2=0;
    long long cnt=0, cnt2=0;
    int s=m, s2=0;
    for (int i=1; i<=n; i++) {
        while (s && a[i]+b[s]>ert) s--;
        sdb[i]=s;
        cnt+=m-s, cnt2+=m-s;
    }
    s=n;
    for (int j=1; j<=m; j++) {
        while (s && a[s]+b[j]>ert) s--;
        odb[j]=s;
    }
    cnt2--;
    maxi=cnt, maxi2=cnt2;
    s=0;
    for (int i=1; i<=n; i++) {
        cnt+=s+sdb[i]-m;
        while (s<m && odb[s+1]+i>=n) {
            s++;
            cnt+=odb[s]+i-n;
        }
        maxi=max(maxi, cnt);
        cnt2+=s2+sdb[i]-m;
        if (i==xx && s2<yy) cnt2++;
        while (s2<m && odb[s2+1]+i>=n) {
            s2++;
            cnt2+=odb[s2]+i-n;
            if (i<xx && s2==yy) cnt2++;
        }
        maxi2=max(maxi2, cnt2);
    }
    return (maxi==maxi2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> b[i];
    xx=a[1], yy=b[1];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    for (int i=1; i<=n; i++) if (a[i]==xx) {
        xx=i;
        break;
    }
    for (int i=1; i<=m; i++) if (b[i]==yy) {
        yy=i;
        break;
    }
    int lo=0, hi=a[xx]+b[yy], mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (jo(mid)) hi=mid;
        else lo=mid;
    }
    cout << hi << "\n";
    return 0;
}
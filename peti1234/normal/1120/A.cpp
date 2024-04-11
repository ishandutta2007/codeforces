#include <bits/stdc++.h>

using namespace std;
int m, k, n, s;
int y;
int cnt;
int f=-1;
int t[500001];
int p[500001];
int e[500001];
void solve(int f)
{
    if (f==-1) {
        cout << -1 << "\n";
        return;
    }
    int q=y-k;
    cout << q << "\n";
    for (int i=f*k+1; i<=f*k+y; i++) {
        if (q>0 && e[t[i]]<=0) {
            cout << i << " ";
            q--;
        } else {
            e[t[i]]--;
        }
    }
    return;
}
int main()
{
    cin >> m >> k >> n >> s;

    y=m-(n-1)*k;
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        if (i<=y) {
            p[x]--;
        }
        t[i]=x;
    }
    for (int i=1; i<=s; i++) {
        int x;
        cin >> x;
        p[x]++;
        e[x]++;
        if (p[x]==1) {
            cnt++;
        }
    }
    for (int i=0; i<n-1; i++) {
        if (cnt==0) {
            f=i;
            break;
        }
        for (int j=i*k+1; j<=(i+1)*k; j++) {
            p[t[j]]++;
            if (p[t[j]]==1) {
                cnt++;
            }
        }
        for (int j=i*k+1+y; j<(i+1)*k+1+y; j++) {
            p[t[j]]--;
            if (p[t[j]]==0) {
                cnt--;
            }
        }

    }
    if (cnt==0 && f==-1) {
        f=n-1;
    }
    solve(f);
    return 0;
}
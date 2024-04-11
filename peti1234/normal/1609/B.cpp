#include <bits/stdc++.h>

using namespace std;
int n, q, t[100005], cnt;
int gc() {
    char c;
    cin >> c;
    return c-'a'+1;
}
void add(int pos, int ert) {
    if (pos<=1 || pos>=n) return;
    if (t[pos-1]==1 && t[pos]==2 && t[pos+1]==3) cnt+=ert;
}
int main()
{
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        t[i]=gc();
    }
    for (int i=1; i<=n; i++) {
        add(i, 1);
    }
    for (int i=1; i<=q; i++) {
        int pos;
        cin >> pos;
        for (int i=pos-2; i<=pos+2; i++) add(i, -1);
        t[pos]=gc();
        for (int i=pos-2; i<=pos+2; i++) add(i, 1);
        cout << cnt << "\n";
    }
    return 0;
}
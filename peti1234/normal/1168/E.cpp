#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int n, a[c], b[c], ia[c], t[c], res[c], xo;
void valt(int p1, int p2) {
    if (p1==p2) return;
    int p3=ia[t[p1]^b[p1]];
    swap(ia[a[p1]], ia[a[p3]]), swap(a[p1], a[p3]);
    swap(b[p2], b[p3]);
    valt(p3, p2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, n=(1<<n);
    for (int i=0; i<n; i++) {
        cin >> res[i], xo^=res[i];
        a[i]=i, b[i]=i, ia[i]=i;
    }
    if (xo) {
        cout << "Fou\n";
        return 0;
    }
    cout << "Shi\n";
    for (int i=0; i<n-1; i++) {
        xo=t[i]^res[i];
        t[i]^=xo, t[i+1]^=xo;
        valt(i, i+1);
    }
    for (int i=0; i<n; i++) cout << a[i] << " ";
    cout << "\n";
    for (int i=0; i<n; i++) cout << b[i] << " ";
    cout << "\n";
    return 0;
}
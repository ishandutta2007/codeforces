#include <bits/stdc++.h>

using namespace std;
int a[200001];
int b[200001];
int c[200001];
int d[200001];
int n;
int kv=1-INT_MAX, nv=INT_MAX, kf=1-INT_MAX, nf=INT_MAX;
bool ker(int x, int y)
{
    int h=0;
    for (int i=1; i<=n; i++) {
        if (x<a[i] || x>c[i] || y<b[i] || y>d[i]) {
            h++;
        }
    }
    if (h<=1) {
        return true;
    }
    return false;
}
int main()
{
    cin >> n; for (int i=1; i<=n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        kv=max(kv, a[i]);
        kf=max(kf, b[i]);
        nv=min(nv, c[i]);
        nf=min(nf, d[i]);
    }
    //cout << kv << " " << nv << " " << kf << " " << nf << endl;
    if (ker(kv, kf)) {
        cout << kv << " " << kf << endl;
        return 0;
    }
    if (ker(nv, kf)) {
        cout << nv << " " << kf << endl;
        return 0;
    }
    if (ker(kv, nf)) {
        cout << kv << " " << nf << endl;
        return 0;
    }
    if (ker(nv, nf)) {
        cout << nv << " " << nf << endl;
        return 0;
    }
    return 0;
}
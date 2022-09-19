#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, ki[c], t[c], pos=1;
bool v[c];
int holvan(int a) {
    if (!ki[a]) return a;
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
int unio(int a, int b) {
    int aa=holvan(a), bb=holvan(b);
    if (aa!=bb) {
        int x=min(t[a], t[b]);
        cout << a << " " << b << " " << x << "\n";
        t[a]-=x, t[b]-=x;
        ki[aa]=bb;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i] >> t[i];
    for (int i=1; i<=n; i++) {
        if (v[i]==0) {
            while(t[i]) {
                while(v[pos]==0 || t[pos]==0) {
                    pos++;
                }
                unio(i, pos);
            }
        }
    }
    bool sp=0;
    for (int i=2; i<=n; i++) {
        if (v[i]!=v[1]) {
            unio(1, i);
            if (!sp) {
                sp=1;
                for (int j=1; j<=n; j++) {
                    if (v[i]!=v[j]) unio(i, j);
                }
            }
        }
    }
    return 0;
}
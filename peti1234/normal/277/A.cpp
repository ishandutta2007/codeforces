#include <bits/stdc++.h>

using namespace std;
int n, m, db, k, u, hv[102];
bool v[102];
int holvan(int x) {
    if (!hv[x]) return x;
    int a=hv[x];
    hv[x]=holvan(a);
    return hv[x];
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) k++, hv[a]=b;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x, el=0;
        cin >> x;
        if (!x) u++;
        for (int i=1; i<=x; i++) {
            int a; cin >> a;
            if (!v[a]) db++, v[a]=1;
            if (el) unio(a, el);
            el=a;
        }
    }
    cout << max(0, db-1-k)+u << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, a[c], b[c], kezd=1, spec=0;
long long sum, cel, o=0;
string p, q;
bool rossz(int a) {
    return (a==-1 || a==10);
}
void lep(int x, int y) {
    if (sum>cel) {
        cout << x << " " << y << "\n";
        sum--;
    }
    a[x]+=y, a[x+1]+=y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p >> q;
    for (int i=1; i<=n; i++) {
        int x=p[i-1]-'0';
        a[i]=x;
    }
    for (int i=1; i<=n; i++) {
        int x=q[i-1]-'0';
        b[i]=x;
    }
    for (int i=1; i<=n; i++) {
        spec=b[i]-a[i]-spec;
        sum+=abs(spec);
    }
    if (spec) {
        cout << -1 << "\n";
        return 0;
    }
    cout << sum << "\n";
    cel=max(o, sum-100000);
    while (sum>cel) {
        while (a[kezd]==b[kezd]) {
            kezd++;
        }
        int dif=b[kezd]-a[kezd];
        if (dif>0) {
            dif=1;
        } else {
            dif=-1;
        }
        int pos=kezd;
        while (rossz(a[pos+1]+dif)) {
            pos++, dif*=-1;
        }
        for (int i=pos; i>=kezd; i--) {
            lep(i, dif);
            dif*=-1;
        }
    }
    return 0;
}
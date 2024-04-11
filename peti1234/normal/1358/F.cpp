#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n;
long long as, bs, a[c], b[c], db;
bool jo=1;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i], as+=a[i];
    for (int i=1; i<=n; i++) cin >> b[i], bs+=b[i];
    if (n==1) {
        if (a[1]==b[1]) cout << "SMALL" << "\n" << 0;
        else cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    if (n==2) {
        long long sm=a[1], bi=a[2], x=b[1], y=b[2], sum=0;
        if (sm>bi) swap(sm, bi);
        if (x<y) swap(x, y);
        while(x>sm) {
            sum+=y/x, y%=x;
            swap(x, y);
        }
        if (x<sm) b[1]=-1, b[2]=-1, sum=0;
        if (x==sm) {
            if ((y-bi)%x) b[1]=-1, b[2]=-1, sum=0;
            else sum+=(y-bi)/x;
        }
        if (sum>c-2) {
            cout << "BIG" << "\n" << sum << "\n";
            return 0;
        }
    }
    while(bs>as) {
        if (b[1]>b[2]) {
            s+='R';
            for (int i=1; i<=n/2; i++) swap(b[i], b[n-i+1]);
        }
        bs=b[n], s+='P', db++;
        for (int i=n; i>1; i--) {
            b[i]-=b[i-1];
            if (b[i]<=0) bs=0;
        }
    }
    for (int i=1; i<=n; i++) if (b[i]!=a[i]) {
        for (int i=1; i<=n/2; i++) swap(b[i], b[n-i+1]);
        s+='R';
        break;
    }
    for (int i=1; i<=n; i++) if (a[i]!=b[i]) jo=0;
    if (!jo) cout << "IMPOSSIBLE" << "\n";
    else if (db>c-2) cout << "BIG" << "\n" << db << "\n";
    else cout << "SMALL" << "\n", reverse(s.begin(), s.end()), cout << s.size() << "\n" << s << "\n";
    return 0;
}
/*
2
1 10
13 14
*/
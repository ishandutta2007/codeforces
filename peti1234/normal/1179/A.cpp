#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long n, q, t[c], t2[c], pos[c], ert, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        pos[i]=pos[i-1];
        if (t[i]>=t[pos[i]]) {
            pos[i]=i;
        }
    }
    ert=pos[n];
    for (int i=ert; i<=n; i++) {
        t2[i-ert+1]=t[i];
    }
    if (ert!=1) {
        a=t[1];
        for (int i=2; i<pos[n]; i++) {
            b=t[i];
            if (a>b) t2[n-ert+i]=b;
            else t2[n-ert+i]=a, a=b;
        }
        t2[n]=a;
    }
    /*for (int i=1; i<=n; i++) {
        cout << t2[i] << " ";
    }
    cout << "\n";*/
    for (int i=1; i<=q; i++) {
        long long x;
        cin >> x;
        if (x<pos[n]) {
            cout << t[pos[x]] << " " << t[x+1] << "\n";
        } else {
            x-=pos[n]-1;
            cout << t2[1] << " " << t2[(x-1)%(n-1)+2] << "\n";
        }
    }
    return 0;
}
/*
3 10
2 1 3
*/
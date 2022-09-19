#include <bits/stdc++.h>

using namespace std;
const int c=1e6;
#define rep(n) for (int i=0; i<n; i++)
int n, kx=c, nx, ky=c, ny, kd=c, nd=-c, a, b, x=-1, y=c, z, p, q;
int main()
{
    cin >> n;
    rep(n) {
        string s; cin >> s, a=0, b=s.size();
        for (int i=0; i<b; i++) a+=s[i]=='B';
        b-=a;
        kx=min(kx, a), nx=max(nx, a), ky=min(ky, b), ny=max(ny, b), kd=min(kd, a-b), nd=max(nd, a-b);
    }
    while(y-x>1) {
        int z=(x+y)/2, a=nx-z, b=kx+z, c=ny-z, d=ky+z, e=nd-z, f=kd+z;
        if (a>b || c>d || e>f || a-d>f || b-c<e) x=z;
        else {
            y=z, p=b, q=d;
            if (b-d>f) p-=b-d-f;
            if (b-d<e) q+=b-d-e;
        }
    }
    cout << y << "\n";
    rep(p) cout << 'B';
    rep(q) cout << 'N';
    return 0;
}
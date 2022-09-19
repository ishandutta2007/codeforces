#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, cnt;
ll xx, yy;
int kerd(long long a, long long b) {
    cnt++;
    a=n-a+1, b=n-b+1;
    cout.flush() << a << " " << b << "\n";
    int ans;
    cin >> ans;
    return ans;
}
void solve(ll kx, ll ky, ll nx, ll ny, ll sx, ll sy) {
    if (sx>nx) {
        solve(kx, sy, nx, ny, kx, sy);
        return;
    }
    if (sy>ny) {
        solve(sx, ky, nx, ny, sx, ky);
        return;
    }
    long long kozx=(sx+nx)/2, kozy=(sy+ny)/2;
    if (cnt%2) {
        kozy=sy;
    } else {
        kozx=sx;
    }
    int s=kerd(kozx, kozy);
    if (!s) {
        return;
    }
    if (s==1) {
        solve(kx, ky, kozx-1, ny, sx, sy);
        return;
    }
    if (s==2) {
        solve(kx, ky, nx, kozy-1, sx, sy);
        return;
    }
    if (s==3) {
        solve(kx, ky, nx, ny, kozx+1, kozy+1);
        return;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    solve(1, 1, n, n, 1, 1);
    return 0;
}
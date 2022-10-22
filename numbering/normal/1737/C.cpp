#include <bits/stdc++.h>
#define int long long
using namespace std;
array<int, 2> A[3];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1] >> A[2][0] >> A[2][1];
        int cen = -1;
        int i, j;
        for(i=0;i<3;i++) {
            if(abs(A[i][0] - A[(i+1)%3][0]) + abs(A[i][1] - A[(i+1)%3][1])== 1) {

            }
            else {
                cen = (i+2) % 3;
            }
        }
        assert(cen != -1);
        int r = A[cen][0], c = A[cen][1];
        int x, y;
        cin >> x >> y;
        if(r==1&&c==1) {
            if(x==1||y==1) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        if(r==1&&c==N) {
            if(x==1||y==N) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        if(r==N&&c==1) {
            if(x==N||y==1) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        if(r==N&&c==N) {
            if(x==N||y==N) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        if((x+1)%2==r%2&&(y+1)%2==c%2) cout << "NO\n";
        else cout << "YES\n";
    }
}
#include <bits/stdc++.h>  
#define N 110
#define M 500010
#define LL __int64
#define inf 0x3f3f3f3f3f3f3f3f
#define lson l,mid,ans<<1 
#define rson mid+1,r,ans<<1|1
#define getMid (l+r)>>1
#define movel ans<<1
#define mover ans<<1|1
using namespace std; 
mt19937 myrand(time(0));
const LL mod = 1e9 + 7; 
int main() {
    cin.sync_with_stdio(false);
    int n, x, y, z, id, ans, start;
    cin >> n >> start >> x;
     ans = -1, id = start;
    for (int i = 0; i < 1000; i++) {
        y = myrand() % n + 1;
        cout << "? " << y << endl;
        fflush(stdout);
        cin >> y >> z;
        if (y > ans&&y < x) {
            ans = y;
            id = z;
        }
    }
    for (int i = 1; i < 1000; i++) {
        if (id == -1) {
            break;
        }
        cout << "? " << id << endl;
        fflush(stdout);
        cin >> y >> z;
        if (y >= x) {
            cout << "! " << y << endl;
            return 0;
        }
        id = z;
    }
    cout << "! -1" << endl;
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
const int p = 1e9 + 7;
int power(int a, int b, int c) {
    a %= c;
    if(b==0) return 1;
    if(b==1) return a;
    if(a==0) return 0;
    if(a==1) return 1;
    if(b%2==0) {
        int k = power(a, b/2, c);
        return k * k % c;
    }
    if(b%2==1) {
        int k = power(a, b-1, c);
        return k * a % c;
    }
}
bool B[1000005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, M;
        int r, c;
        int x2, y2;
        cin >> N >> M;
        cin >> r >> c >> x2 >> y2;
        int m;
        cin >> m;
        int dr = 1, dc = 1;
        int cnt = 0;
        int r2 = r, c2 = c;
        int i;
        int dr1 = 1, dc1 = 1;
        if(r==N) dr1 = -1;
        if(c==M) dc1 = -1;
        while(true) {
            //cout << cnt << ' ' << r << ' ' << c << '\n';
            B[cnt] = false;
            if(r==x2||c==y2) B[cnt] = true;
            if(r==N&&dr==1) dr = -1;
            if(r==1&&dr==-1) dr = 1;
            if(c==M&&dc==1) dc = -1;
            if(c==1&&dc==-1) dc = 1;
            r += dr;
            c += dc;
            cnt++;
            if(r == r2 && c == c2 && dr == dr1 && dc == dc1) break;
            if(r==N&&dr==1) dr = -1;
            if(r==1&&dr==-1) dr = 1;
            if(c==M&&dc==1) dc = -1;
            if(c==1&&dc==-1) dc = 1;
            if(r == r2 && c == c2 && dr == dr1 && dc == dc1) break;
        }
        int sum = 0;
        for(i=0;i<cnt;i++) {
            if(B[i]) sum++;
        }
        int x = 0;
        int i2 = 0;
        for(i=0;i<cnt;i++) {
            if(!B[i]) continue;
            //cout << i << '\n';
            int d = m * power(100-m,i2, p) % p;
            d = d * power(100,sum-i2-1,p) % p;
            d = d * i % p;
            x = (x + d) % p;
            i2++;
        }
        //cout <<sum << '\n';
        x += power(100-m,sum,p)*cnt % p;
        x %= p;
        int y = power(100, sum, p);
        y += p - power(100-m,sum,p);
        y %= p;
        //cout << x << ' ' << y << '\n';
        x = x * power(y, p-2, p) % p;
        cout << x << '\n';
    }
}
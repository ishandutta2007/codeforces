#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL tt[2][1200001];
LL val[2][500001];
string s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, h, w; cin >> n >> h >> w >> s;
    int x = 600000, y = 600000;

    memset(tt, -1, sizeof tt);

    tt[0][x] = tt[1][y] = 0;
    int mnx = x, mxx = x, mny = y, mxy = y;
    REP(i, n){
        if(s[i] == 'U') x--;
        else if(s[i] == 'D') x++;
        else if(s[i] == 'L') y--;
        else y++;

        if(tt[0][x] == -1) tt[0][x] = i+1;
        if(tt[1][y] == -1) tt[1][y] = i+1;

        mnx = min(mnx, x);
        mxx = max(mxx, x);
        mny = min(mny, y);
        mxy = max(mxy, y);
    }



    int reqH = mxx - mnx + 1, reqW = mxy - mny + 1;
    if(reqH <= h && reqW <= w && x == 600000 && y == 600000){
        cout << -1 << endl;
        return 0;
    }

    int dx = x-600000, dy = y-600000;
    if(dx < 0){
        for(int i = mnx-1; i >= 0; i--){
            tt[0][i] = tt[0][i-dx] + n;
        }
    } else if(dx > 0){
        for(int i = mxx + 1; i <= 1200000; i++){
            tt[0][i] = tt[0][i-dx] + n;
        }
    }

    if(dy < 0){
        for(int i = mny-1; i >= 0; i--){
            tt[1][i] = tt[1][i-dy] + n;
        }
    } else if(dy > 0){
        for(int i = mxy + 1; i <= 1200000; i++){
            tt[1][i] = tt[1][i-dy] + n;
        }
    }


    for(int i = 0; i <= 1200000; i++){
        if(tt[0][i] == -1) tt[0][i] = mod*mod;
        if(tt[1][i] == -1) tt[1][i] = mod*mod ;
    }

    for(int i = 1; i <= w; i++){
        val[1][i] = min(tt[1][600000-i], tt[1][600000+w+1-i]);
    }
    for(int i = 1; i <= h; i++){
        val[0][i] = min(tt[0][600000-i], tt[0][600000+h+1-i]);
    }



    sort(val[0]+1, val[0]+h+1);
    sort(val[1]+1, val[1]+w+1);

    assert(val[0][h] != mod || val[1][h] != mod);

    int rgt = 1;
    LL sum = 0, res = 0;
    for(int i = 1; i <= h; i++){
        while(rgt <= w && val[1][rgt] <= val[0][i]) {
            sum += val[1][rgt];
            rgt++;
        }

        res += sum + val[0][i] * (w - rgt + 1);
        res %= mod;
    }

    cout << res << endl;
}
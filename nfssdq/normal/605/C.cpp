/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

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

#define eps 1e-12
typedef pair<LL, LL> point;

bool cw(const point &a, const point &b, const point &c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

vector<point> convexHull(vector<point> p) {
    int n = p.size();
    if (n <= 1)
        return p;
    sort(p.begin(), p.end());
    int cnt = 0;
    vector<point> q(n * 2);
    for (int i = 0; i < n; q[cnt++] = p[i++])
        for (; cnt >= 2 && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p[i--])
        for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    q.resize(cnt - 1 - (q[0] == q[1]));
    return q;
}


vector < point > vc, conv;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    double p, q; cin >> n >> p >> q;
    int mx = 0, my = 0;
    REP(i, n){
        int x, y; cin >> x >> y;
        vc.pb(mp(x, y));
        mx = max(mx, x);
        my = max(my, y);
    }
    vc.pb(mp(0, 0));
    vc.pb(mp(0, my));
    vc.pb(mp(mx, 0));

    conv = convexHull(vc);

    int len = conv.size();
    double lo = 0.0, hi = 4e6;
    REP(ts, 400){
        double mid = (lo + hi) / 2.0;
        int fl = 0;
        double tmp = (double)conv[len-1].xx * mid;
        if(tmp < p - eps) fl = 1;
        tmp = (double)conv[1].yy * mid;
        if(tmp < q - eps) fl = 1;

        if(fl == 0){
            fl = 1;
            for(int i = 2; i < len; i++){
                double px = (double)conv[i-1].xx * mid;
                double py = (double)conv[i-1].yy * mid;
                double qx = (double)conv[i].xx * mid;
                double qy = (double)conv[i].yy * mid;


                if(px > p + eps) break;

                if(qx < p - eps) continue;
                if(abs(qx-p) < eps && qy > q - eps) {
                    fl = 0;
                    break;
                }
                if(abs(qx - p) < eps) break;

                double y = (p - qx) * (qy - py) / (qx - px);
                y += qy;

//                if(ts == 19) cout << i << " " << mid << " " << px << " " << py << " " << qx << " " << qy << " " << y << endl;

                if(y > q - eps) {
                    fl = 0;
                    break;
                }

            }
//            cout << fl << endl;
        }

//        cout << lo << " " << hi << " " << fl << endl;
        if(fl == 0) hi = mid;
        else lo = mid;

    }

    cout << fixed << setprecision(10) << lo << endl;
}
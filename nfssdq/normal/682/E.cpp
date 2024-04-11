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

vector < point > vc, hull;

LL area(point p1, point p2, point p3){
    LL ret = (p1.xx*p2.yy + p2.xx*p3.yy + p3.xx*p1.yy) - (p1.yy*p2.xx + p2.yy*p3.xx + p3.yy*p1.xx);
    if(ret < 0) ret *= -1;
    return ret;
}

void go(int x, int y, int z){
    point p1, p2, p3;
    p1 = mp(hull[z].xx - hull[x].xx + hull[y].xx, hull[z].yy - hull[x].yy + hull[y].yy);
    p2 = mp(hull[z].xx - hull[y].xx + hull[x].xx, hull[z].yy - hull[y].yy + hull[x].yy);
    p3 = mp(hull[x].xx + hull[y].xx - hull[z].xx, hull[x].yy + hull[y].yy - hull[z].yy);
    cout << p1.xx << " " << p1.yy << endl;
    cout << p2.xx << " " << p2.yy << endl;
    cout << p3.xx << " " << p3.yy << endl;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; LL S; cin >> n >> S;
    REP(i, n){
        int x, y; cin >> x >> y;
        vc.pb(mp(x, y));
    }
    hull = convexHull(vc);
    if(hull.size() == 3){
        cout << 3 << endl;
        REP(i, 3) cout << hull[i].xx << " " << hull[i].yy << endl;
    }

    int x, y, z;
    LL mx = 0;
    for(int i = 0; i < hull.size() - 1; i++){
        int lft = i+1, rgt = i;
        for(int j = i+1; j < hull.size(); j++){
            while(lft < hull.size()-1 && area(hull[lft], hull[i], hull[j]) <= area(hull[lft+1], hull[i], hull[j])) lft++;
            while(rgt < j && area(hull[rgt], hull[i], hull[j]) <= area(hull[rgt+1], hull[i], hull[j])) rgt++;
            if(area(hull[lft], hull[i], hull[j]) > mx){
                mx = area(hull[lft], hull[i], hull[j]);
                x = i;
                y = j;
                z = lft;
            }
            if(area(hull[rgt], hull[i], hull[j]) > mx){
                mx = area(hull[rgt], hull[i], hull[j]);
                x = i;
                y = j;
                z = rgt;
            }
        }
    }
//    cout << mx << endl;

    go(x, y, z);
}
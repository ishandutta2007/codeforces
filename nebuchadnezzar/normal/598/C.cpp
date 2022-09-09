#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const ll MOD = 6e17;

/*
ll mpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll tmp = mpow(a, b / 2);
    tmp = tmp * tmp;
    if (b & 1) {
        tmp = tmp * a;
    }
    return tmp;
}*/

ll dd[18];

struct number {
    ll a, b;
    number(ll num) {
        a = num / MOD;
        b = num % MOD;
    }
    number(ll _a, ll _b) {
        a = _a;
        b = _b;
    }
    number operator+(number n) {
        ll tmp = b + n.b;        
        return number(a + n.a + tmp / MOD, tmp % MOD);
    }
    number operator*(ll n) {
        ll tmp = n;
        number ret = number(0);
        for (int i = 0; i < 9; ++i) {
            int q = tmp % 10;
            ll now = q * b;
            ret.a += now / (MOD / dd[i]);
            ret.b += now % (MOD / dd[i]) * dd[i];
            ret.a += a * (q * dd[i]);
            tmp /= 10;
        }
        ret.a += ret.b / MOD;
        ret.b %= MOD;
            
        return ret;
    }
    bool operator>(number n) {
        if (a != n.a) {
            return a > n.a;
        }
        return b > n.b;
    }
    bool operator<(number n) {
        if (a != n.a) {
            return a < n.a;
        }
        return b < n.b;
    }
};

struct point {
    ll x, y;
    int num;
    point(ll _x, ll _y, int _num) {
        x = _x;
        y = _y;
        num = _num;
    }
    point() {
        x = y = 0;
    }
    ll operator*(point p) {
        return x * p.y - y * p.x;
    }
    ll operator/(point p) {
        return x * p.x + y * p.y;
    }
    ll len() {
        return x * x + y * y;
    }
};

int n;
vector <point> u, d;

bool cmp(point p1, point p2) {
    return p1 * p2 < 0;
}

bool cmp2(pii a, pii b) {
    ll tmp1 = u[a.ff] / u[a.ss];
    ll tmp2 = u[b.ff] / u[b.ss];
    //cerr << tmp1 << " " << tmp2 << endl;
    //cerr << tmp1 << " " << tmp1 * tmp1 << " " << (number(tmp1) * tmp1).b << endl;

    if (tmp1 <= 0 && tmp2 > 0) {
        return false;
    }
    if (tmp2 <= 0 && tmp1 > 0) {
        return true;
    }

    if (tmp1 <= 0 && tmp2 <= 0) {
        return number(tmp1 * tmp1) * u[b.ff].len() * u[b.ss].len() < number(tmp2 * tmp2) * u[a.ff].len() * u[a.ss].len();
    }

    return number(tmp1 * tmp1) * u[b.ff].len() * u[b.ss].len() > number(tmp2 * tmp2) * u[a.ff].len() * u[a.ss].len();
}

int main() {
    dd[0] = 1;
    for (int i = 1; i < 18; ++i) {
        dd[i] = dd[i - 1] * 10;
    }
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    /*
    {         
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    number tmp = number(a) * b * c * d;

    cout << tmp.a << " " << tmp.b << endl;
    }
    return 0;
    */
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y > 0) {
            u.puba(point(x, y, i));
        } else {
            d.puba(point(x, y, i));
        }
    }

    sort(bend(u), cmp);
    sort(bend(d), cmp);

    for (auto p: d) {
        u.puba(p);
    }
    /*
    for (auto p: u) {
        cerr << p.x << " " << p.y << " " << p.num << endl;
    }*/

    vector <pii> ans;
    for (int i = 0; i < n; ++i) {
        ans.puba({i, (i + 1) % n});
        //int a = i;
        //int b = (i + 1) % n;
        //cerr << u[a] / u[b] << " " << u[a].len() << " " << u[b].len() << " " << u[a] / u[b] / sqrt(u[a].len() * u[b].len()) << " " << u[a].num << " " << u[b].num << endl;
    }

    //sort(bend(ans), cmp2);

    int best = 0;
    for (int i = 1; i < szof(ans); ++i) {
        if (cmp2(ans[i], ans[best])) {
            best = i;
        }
    }

    cout << u[ans[best].ff].num + 1 << " " << u[ans[best].ss].num + 1 << endl;

    return 0;
}
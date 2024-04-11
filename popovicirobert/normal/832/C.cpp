#include <bits/stdc++.h>
#define ll long long

const int MAXN = (int) 1e5;

using namespace std;


struct Data {
    long double x;
    long double s;
    int t;
}v[MAXN + 1];

int sp[2][10 * MAXN + 2];
long double s;
int n;

const long double eps = 1e-9;

inline long double calc(long double x) {
    if(x - floor(x) < eps)
        return floor(x);
    return floor(x) + 1;
}

inline bool check(long double t) {
    int i;
    memset(sp, 0, sizeof(sp));
    for(i = 1; i <= n; i++) {
        long double d;
        if(v[i].t == 1)
            d = v[i].x;
        else
            d = (long double) 1e6 - v[i].x;
        if(t * v[i].s - d >= 0) {
            sp[v[i].t - 1][1]++;
            sp[v[i].t - 1][(int) 1e6 + 1]--;
        }
        else {
            long double t1 = (t * (v[i].s + s) - d) / s;
            if(t1 >= 0) {
                if(v[i].t == 1) {
                     sp[0][(int) floor(min((long double) 1e6, v[i].x + t1 * (s - v[i].s))) + 1]--;
                     sp[0][(int) floor(v[i].x)]++;
                }
                else {
                     sp[1][(int) floor(max((long double) 1.0, calc(v[i].x - t1 * (s - v[i].s))))]++;
                     sp[1][(int) floor(v[i].x) + 1]--;
                }
            }
        }
    }
    for(i = 1; i <= (int) 1e6; i++) {
        sp[0][i] += sp[0][i - 1];
        sp[1][i] += sp[1][i - 1];
        if(sp[0][i] > 0 && sp[1][i] > 0)
           return 1;
    }
    return 0;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for(i = 1; i <= n; i++)
        cin >> v[i].x >> v[i].s >> v[i].t;
    long double l, r;
    l = 0;
    r = 1e6;
    for(i = 0; i < 50; i++) {
        long double med = (l + r) / 2;
        if(check(med) == 1)
            r = med;
        else
            l = med;
    }
    cout << setprecision(20) << (l + r) / 2;
    //cin.close();
    //cout.close();
    return 0;
}
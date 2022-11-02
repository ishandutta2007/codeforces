#include <bits/stdc++.h>
        
using namespace std;
        
mt19937 rnd(time(0));
        
//        //\\      ||||||  ||||          //\\        ||||||
//       //  \\       ||    ||  ||       //  \\       ||   ||
//      //    \\      ||    ||   ||     //    \\      ||   ||
//     //------\\     ||    ||   ||    //------\\     ||||||
//    //        \\    ||    ||   ||   //        \\    ||  \\
//   //          \\ ||||||  |||||    //          \\   ||   \\
        
#define AIDAR ASADULLIN
        
#define int long long
#define mp make_pair
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define fi first
#define se second
#define double long double
#define size(a) (int)(a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
 
const int inf = 1e9;
const int max_n = 1e5 + 3;

struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}

    point operator+ (const point& a)const {
        return point(x + a.x, y + a.y);
    }

    point operator- (const point& a)const {
        return point(x - a.x, y - a.y);
    }

    int operator% (const point& a)const {
        return x * a.y - y * a.x;
    }
};

struct line {
    point a, b;

    line() {}
    line(point a, point b) : a(a), b(b) {}

    bool in(point c) {
        return !((b - a) % (c - a));
    }
};

int n;
point p[max_n];

bool check(line a) {
    vector<int> oth;
    for(int i = 0;i < n;i++) {
        if (!a.in(p[i])) 
            oth.emplace_back(i);
    }
    if (size(oth) < 2) return true;

    line b = line(p[oth[0]], p[oth[1]]);
    for(int i : oth) {
        if (!b.in(p[i])) return false;
    }
    return true;
}

bool solve() {
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> p[i].x >> p[i].y;

    if (n <= 2) return true;
    return check(line(p[0], p[1])) || check(line(p[0], p[2])) || check(line(p[1], p[2]));
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(15);
        
#ifdef technocum
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << (solve() ? "YES" : "NO") << endl;
}
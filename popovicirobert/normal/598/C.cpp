#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

pair <long double, int> pts[MAXN + 1];
const long double pi = acos(-1);

inline long double calc(long double x) {
   if(x < 0)
      x = -x;
   return min(x, 2 * pi - x);
}


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        long double x, y;
        cin >> x >> y;
        pts[i].first = atan2(x, y);
        pts[i].second = i;
    }
    sort(pts + 1, pts + n + 1);
   // for(i = 1; i <= n; i++)
    //    printf("%f %d\n" ,pts[i].first,pts[i].second);
    int p = 2;
    for(i = 3; i <= n; i++)
        if(calc(pts[i].first - pts[i - 1].first) < calc(pts[p].first - pts[p - 1].first))
            p = i;
    if(calc(pts[n].first - pts[1].first) < calc(pts[p].first - pts[p - 1].first))
        cout << pts[1].second << " " << pts[n].second;
    else
        cout << pts[p].second << " " << pts[p - 1].second;
    //cin.close();
    //cout.close();
    return 0;
}
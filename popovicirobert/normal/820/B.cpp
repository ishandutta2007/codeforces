#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    double a;
    ios::sync_with_stdio(false);
    cin >> n >> a;
    double x = 180.0 / n;
    double mn = 1000000;
    int cnt = 3, v;
    while(x <= a && cnt <= n) {
          //  printf("%lf ")
        if(mn > abs(x - a)) {
            mn = abs(x - a);
            v = cnt;
        }
        x += 180.0 / n;
        cnt++;
    }
    if(mn > abs(x - a) && cnt <= n) {
        mn = abs(x - a);
        v = cnt;
    }
    cout << 2 << " " << 1 << " " << v;
    //cin.close();
   // cout.close();
    return 0;
}
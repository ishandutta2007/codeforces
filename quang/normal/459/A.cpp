#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int xx1, yy1, xx2, yy2;

int main()
{
    //fi, fo;
    scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
    if(xx1 != xx2 && yy1 != yy2) {
        if(abs(xx1 - xx2) != abs(yy1 - yy2)) {
            cout << -1;
            return 0;
        }
        cout << xx1 << " " << yy2 << " " << xx2 << " " << yy1;
        return 0;
    }
    if(xx1 == xx2) {
        int kc = abs(yy1 - yy2);
        if(xx1 + kc <= 1000) {
            cout << xx1 + kc << " " << yy1 << " " << xx2 + kc << " " << yy2;
            return 0;
        }
        if(xx1 - kc >= -1000) {
            cout << xx1 - kc << " " << yy1 << " " << xx2 - kc << " " << yy2;
            return 0;
        }
        cout << -1;
        return 0;
    }
    if(yy1 == yy2) {
        int kc = abs(xx1 - xx2);
        if(yy1 + kc <= 1000) {
            cout << xx1 << " " << yy1 + kc << " " << xx2 << " " << yy1 + kc;
            return 0;
        }
        if(yy1 - kc >= -1000) {
            cout << xx1 << " " << yy1 - kc << " " << xx2 << " " << yy1 - kc;
            return 0;
        }
        cout << -1;
        return 0;
    }
    return 0;
}
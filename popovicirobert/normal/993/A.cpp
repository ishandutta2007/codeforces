#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

struct Square {
    int x[5];
    int y[5];
}A, B;

inline bool in(double x, double y, Square A) {
    int mnx = min(min(A.x[0], A.x[1]), min(A.x[2], A.x[3]));
    int mxx = max(max(A.x[0], A.x[1]), max(A.x[2], A.x[3]));
    int mny = min(min(A.y[0], A.y[1]), min(A.y[2], A.y[3]));
    int mxy = max(max(A.y[0], A.y[1]), max(A.y[2], A.y[3]));
    return mnx <= x && x <= mxx && mny <= y && y <= mxy;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    for(i = 0; i < 4; i++) {
        cin >> A.x[i] >> A.y[i];
    }
    for(i = 0; i < 4; i++) {
        cin >> B.x[i] >> B.y[i];
    }
    bool ans = 0;
    for(int t = 0; t < 2; t++) {
        for(i = 0; i < 4; i++) {
            ans |= in(B.x[i], B.y[i], A);
        }
        for(i = 0; i < 4; i++) {
            int x = A.x[i];
            int y = A.y[i];
            A.x[i] = x - y;
            A.y[i] = x + y;
            x = B.x[i];
            y = B.y[i];
            B.x[i] = x - y;
            B.y[i] = x + y;
        }
        swap(A, B);
    }
    if(ans)
        cout << "YES";
    else {
        for(int i = -100; i <= 100; i++) {
            for(int j = -100; j <= 100; j++) {
                Square aux;
                for(int p = 0; p < 4; p++) {
                    aux.x[p] = B.x[p] - B.y[p];
                    aux.y[p] = B.x[p] + B.y[p];
                }
                int x = i - j;
                int y = i + j;
                if(in(i, j, A) && in(x, y, aux)) {
                    cout << "YES";
                    return 0;
                }
            }
        }
        cout << "NO";
    }
    //cin.close();
    //cout.close();
    return 0;
}
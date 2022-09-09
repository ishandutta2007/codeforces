#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define puba push_back
#define mapa make_pair

using namespace std;

struct bomb {
    int x, y, kx, ky;
};

struct op {
    int type, l;
    char dir;
};

vector <bomb> mas;
int x, y, n, num;
bomb b1;
vector <op> ans;
op op1;

bool comp(bomb b1, bomb b2) {
    if (b1.x == b2.x) {
        return b1.y < b2.y;
    }
    return b1.x < b2.x;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (x < 0) {
            b1.kx = -1;
        } else {
            b1.kx = 1;
        }

        if (y < 0) {
            b1.ky = -1;
        } else {
            b1.ky = 1;
        }
        b1.x = abs(x);
        b1.y = abs(y);
        mas.puba(b1);
    }
    sort(mas.begin(), mas.end(), comp);

    for (int i = 0; i < n; ++i) {
        if (mas[i].x == 0) {
            if (mas[i].ky == -1) {
                op1.dir = 'D';
            } else {
                op1.dir = 'U';
            }
            op1.type = 1;
            op1.l = mas[i].y;
            ans.puba(op1);
            op1.type = 2;
            ans.puba(op1);
            op1.type = 1;
            if (mas[i].ky == -1) {
                op1.dir = 'U';
            } else {
                op1.dir = 'D';
            }
            ans.puba(op1);
            op1.type = 3;
            ans.puba(op1);
        } else if (mas[i].y == 0) {
            if (mas[i].kx == -1) {
                op1.dir = 'L';
            } else {
                op1.dir = 'R';
            }
            op1.type = 1;
            op1.l = mas[i].x;
            ans.puba(op1);
            op1.type = 2;
            ans.puba(op1);
            op1.type = 1;
            if (mas[i].kx == -1) {
                op1.dir = 'R';
            } else {
                op1.dir = 'L';
            }
            ans.puba(op1);
            op1.type = 3;
            ans.puba(op1);
        } else {
            if (mas[i].ky == -1) {
                op1.dir = 'D';
            } else {
                op1.dir = 'U';
            }
            op1.type = 1;
            op1.l = mas[i].y;
            ans.puba(op1);

            if (mas[i].kx == -1) {
                op1.dir = 'L';
            } else {
                op1.dir = 'R';
            }
            op1.type = 1;
            op1.l = mas[i].x;
            ans.puba(op1);

            op1.type = 2;
            ans.puba(op1);
            
            op1.type = 1;
            if (mas[i].ky == -1) {
                op1.dir = 'U';
            } else {
                op1.dir = 'D';
            }
            op1.l = mas[i].y;
            ans.puba(op1);

            op1.type = 1;
            if (mas[i].kx == -1) { //1
                op1.dir = 'R';
            } else {
                op1.dir = 'L';
            }
            op1.l = mas[i].x;
            ans.puba(op1);

            op1.type = 3;
            ans.puba(op1);
        }
    }

    cout << ans.size() << endl;

    for (int i = 0; i < (int) ans.size(); ++i) {
        if (ans[i].type == 1) {
            cout << "1 " << ans[i].l << " " << ans[i].dir << endl;
        } else {
            cout << ans[i].type << endl;
        }

    }

    return 0;
}
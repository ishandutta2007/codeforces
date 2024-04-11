#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
struct view {
    int t, l, r;            
};


int n, m, s, f, step;
char mainch;
view v;
vector <view> mas;

int main() {
    cin >> n >> m >> s >> f;
    if (s < f) {
        mainch = 'R';
        step = 1;
    } else {
        mainch = 'L';
        step = -1;
    }

    for (int i = 0; i < m; ++i) {
        cin >> v.t >> v.l >> v.r;
        mas.push_back(v);
    }
    int last_num = 0, now_time = 1;

    while (s != f) {
        if (last_num < (int) mas.size() && now_time == mas[last_num].t) {
            if ((s < mas[last_num].l || s > mas[last_num].r) && (s + step < mas[last_num].l || s + step > mas[last_num].r)) {
                cout << mainch;
                s += step;
            } else {
                cout << 'X';
            }
            ++last_num;
        } else {
            cout << mainch;
            s += step;
        }
        ++now_time;
    }

    return 0;
}
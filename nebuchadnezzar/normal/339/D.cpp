#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
int bsb;
long long roq[300000];
int num, n, pos, l, r, k, m, p, b;
int x, y, t;
/*
int my_sum(int v, int vl, int vr, int gl, int gr) {
    if (vr < gl || gr < vl) {
        return 0;
    }
    if (gl <= vl && vr <= gr) {
        //cout << "@ " << gl << " " << gr << " " << vl << " " << vr << " \n";
        return rsq[v];
    }
    int vm = (vl + vr) / 2;
    return my_sum(v * 2, vl, vm, gl, gr) + my_sum(v * 2 + 1, vm + 1, vr, gl, gr);
//    return max(my_max(v * 2, vl, vm, gl, gr), my_max(v * 2 + 1, vm + 1, vr, gl, gr));
} */

int my_add(int p, int num) {
    int mp = bsb / 2 + p;
    roq[mp] = num;
    int mem = 0;
    for (mp = mp / 2; mp >= 1; mp = mp / 2) {
        if (mem % 2 == 0) {
            roq[mp] = roq[mp * 2] | roq[mp * 2 + 1];
        } else {
            roq[mp] = roq[mp * 2] ^ roq[mp * 2 + 1];
        }
        ++mem;
    }
    return 0;
}

void preparation() {
    for (int i = 0; i < bsb; ++i) {
        roq[i] = 0;
    }
}

int main() {
    //freopen("inp.txt", "r", stdin);
    //cout << "@";
    preparation();

    cin >> n >> m;
    bsb = 2;
    for (int i = 0; i < n; ++i) {
        bsb *= 2;
    }

    //n = bsb / 2;
    for (int i = 0; i < bsb / 2; ++i) {
        cin >> num;
        my_add(i, num);
    }

/*
    cout << endl;
    for (int i = 0; i < bsb; ++i) {
        cout << rsq[i] << " ";
    }
    cout << endl;
*/
    for (int i = 0; i < m; ++i) {
        //cout << "#" << endl;
        cin >> p >> b;
        //cout << "1";
        my_add(p - 1, b);
        cout << roq[1] << endl;
    }

    return 0;
}
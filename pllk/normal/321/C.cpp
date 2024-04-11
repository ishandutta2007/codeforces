#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v[100000];
int q[100000];

void tee(int x, int b) {
    int m = 0, t = 0;
    vector<int> w;
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i] == b) continue;
        tee(v[x][i], x);
        w.push_back(q[v[x][i]]);
    }
    int kk = 1;
    int sy = -1, sk = -1;
    int pp = 0;
    for (int i = 0; i < 20; i++) {
        int t = 0;
        for (int j = 0; j < w.size(); j++) {
            if (w[j]&kk) t++;
            pp |= w[j];
        }
        if (t >= 1) sy = i+1;
        if (t >= 2) sk = i+1;
        kk *= 2;
    }
    if (sy == -1) {
        q[x] = 1;
    } else if (w.size() == 1) {
        q[x] = w[0]+1;
    } else if (sy == sk) {
        q[x] = 1<<(sy+1);
    } else {
        int aa = 0;
        if (sk == -1) aa = 1;
        else aa = 1<<(sk+1);
        while (pp&aa) aa *= 2;
        if (aa > (1<<sy)) q[x] = aa;
        else q[x] = (1<<sy)+aa;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    tee(0, -1);
    for (int i = 0; i < n; i++) {
        int kk = 1;
        int z;
        //cout << q[i] << endl;
        for (int j = 0; j < 20; j++) {
            if (q[i]&kk) {
                z = j;
                break;
            }
            kk *= 2;
        }
        cout << (char)('Z'-z) << " ";
    }
    cout << endl;
}
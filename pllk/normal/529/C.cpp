#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, q;

vector<pair<int,int>> v1, v2;

#define N (1<<17)
int p[2*N];

void muuta(int k, int x) {
    k += N;
    p[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = min(p[2*k], p[2*k+1]);
    }
}

int pienin(int a, int b) {
    a += N; b += N;
    int t = 999999999;
    while (a <= b) {
        if (a%2 == 1) t = min(t, p[a++]);
        if (b%2 == 0) t = min(t, p[b--]);
        a /= 2; b /= 2;
    }
    return t;
}

int qq[202020][4];
vector<pair<int,int>> q1, q2;
int vv[202020];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        v1.push_back(make_pair(y,x));
        v2.push_back(make_pair(x,y));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        qq[i][0] = x1;
        qq[i][1] = y1;
        qq[i][2] = x2;
        qq[i][3] = y2;
        q1.push_back(make_pair(y2,i));
        q2.push_back(make_pair(x2,i));
    }
    sort(q1.begin(), q1.end());
    sort(q2.begin(), q2.end());
    int j = -1;
    for (int i = 0; i < q; i++) {
        int y = q1[i].first;
        while (j+1 < v1.size() && v1[j+1].first <= y) {
            j++;
            muuta(v1[j].second, v1[j].first);
        }
        int id = q1[i].second;
        int x1 = qq[id][0];
        int y1 = qq[id][1];
        int x2 = qq[id][2];
        int y2 = qq[id][3];
        int u = pienin(x1, x2);
        if (u >= y1) vv[id] = 1;
    }
    for (int i = 0; i < 2*N; i++) p[i] = 0;
    j = -1;
    for (int i = 0; i < q; i++) {
        int x = q2[i].first;
        while (j+1 < v2.size() && v2[j+1].first <= x) {
            j++;
            muuta(v2[j].second, v2[j].first);
        }
        int id = q2[i].second;
        int x1 = qq[id][0];
        int y1 = qq[id][1];
        int x2 = qq[id][2];
        int y2 = qq[id][3];
        int u = pienin(y1, y2);
        if (u >= x1) vv[id] = 1;
    }
    for (int i = 0; i < q; i++) {
        if (vv[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}
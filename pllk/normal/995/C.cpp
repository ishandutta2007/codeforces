#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define F first
#define S second

#define V vector<vector<int>>

int n;
V v1, v2, v3;
int r[101010];

void lol(V &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i][0] < 0) {
            v[i][0] = -v[i][0];
            v[i][1] = -v[i][1];
            v[i][3] = -v[i][3];
        }
    }
    sort(v.begin(),v.end());
    int cc = 0;
    for (int i = 0; i+1 < v.size(); i += 2) {
        v[i+1][0] = -v[i+1][0];
        v[i+1][1] = -v[i+1][1];
        v[i+1][3] = -v[i+1][3];
        int uu = v[i][1]+v[i+1][1];
        if ((cc > 0 && uu > 0) || (cc < 0 && uu < 0)) {
            v[i][0] = -v[i][0];
            v[i][1] = -v[i][1];
            v[i+1][0] = -v[i+1][0];
            v[i+1][1] = -v[i+1][1];
            v[i][3] = -v[i][3];
            v[i+1][3] = -v[i+1][3];
        }
        cc += v[i][1]+v[i+1][1];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (abs(x) >= 500000) {
            v1.push_back({x,y,i,1});
        } else if (abs(y) >= 500000) {
            v2.push_back({x,y,i,1});
        } else {
            v3.push_back({x,y,i,1});
        }
    }
    lol(v1);
    for (int i = 0; i < v2.size(); i++) swap(v2[i][0],v2[i][1]);
    lol(v2);
    for (int i = 0; i < v2.size(); i++) swap(v2[i][0],v2[i][1]);
    lol(v3);
    for (int a = -1; a <= 1; a++)
    for (int b = -1; b <= 1; b++)
    for (int c = -1; c <= 1; c++) {
        if (a == 0 || b == 0 || c == 0) continue;
        double aa = 0, bb = 0;
        for (auto x : v1) {aa += a*x[0]; bb += a*x[1];}
        for (auto x : v2) {aa += b*x[0]; bb += b*x[1];}
        for (auto x : v3) {aa += c*x[0]; bb += c*x[1];}
        if (sqrt(aa*aa+bb*bb) <= 1.5*1e6) {
            for (auto x : v1) r[x[2]] = a*x[3];
            for (auto x : v2) r[x[2]] = b*x[3];
            for (auto x : v3) r[x[2]] = c*x[3];
            for (int i = 0; i < n; i++) cout << r[i] << " ";
            cout << "\n";
            return 0;
        }
    }
}
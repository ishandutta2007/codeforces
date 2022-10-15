#include <iostream>

using namespace std;

typedef long long ll;

int N;

#define INF 999999999999999LL

// // /\ \/ \\ x
ll p[1<<20][4];

void setVal(int k, int x) {
    k += N;
    p[k][0] = x;
    p[k][1] = -x;
    p[k][2] = -INF;
    p[k][3] = -x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k][0] = max(p[2*k][0]+p[2*k+1][2],p[2*k][1]+p[2*k+1][0]);
        p[k][0] = max(p[k][0],p[2*k][0]);
        p[k][0] = max(p[k][0],p[2*k+1][0]);
        p[k][1] = max(p[2*k][0]+p[2*k+1][3],p[2*k][1]+p[2*k+1][1]);
        p[k][1] = max(p[k][1],p[2*k][1]);
        p[k][1] = max(p[k][1],p[2*k+1][1]);
        p[k][2] = max(p[2*k][2]+p[2*k+1][2],p[2*k][3]+p[2*k+1][0]);
        p[k][2] = max(p[k][2],p[2*k][2]);
        p[k][2] = max(p[k][2],p[2*k+1][2]);
        p[k][3] = max(p[2*k][2]+p[2*k+1][3],p[2*k][3]+p[2*k+1][1]);
        p[k][3] = max(p[k][3],p[2*k][3]);
        p[k][3] = max(p[k][3],p[2*k+1][3]);
    }
}

void print() {
    return;
    for (int i = 1; i < 2*N; i++) {
        cout << i << " " << p[i][0] << " " << p[i][1] << " " << p[i][2] << " " << p[i][3] << "\n";
    }
}

ll answer() {
    return max(max(p[1][0],p[1][1]),max(p[1][2],p[1][3]));
}

int n, q;
int a[303030];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        N = 1;
        while (N <= n) N *= 2;
        for (int i = 0; i < 2*N; i++) {
            p[i][0] = -INF;
            p[i][1] = -INF;
            p[i][2] = -INF;
            p[i][3] = -INF;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            setVal(i,a[i]);
        }
        print();
        cout << answer() << "\n";
        for (int i = 1; i <= q; i++) {
            int x, y;
            cin >> x >> y;
            swap(a[x],a[y]);
            setVal(x,a[x]);
            setVal(y,a[y]);
            print();
            cout << answer() << "\n";
        }
    }
}
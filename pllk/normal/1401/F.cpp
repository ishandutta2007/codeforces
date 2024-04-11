#include <iostream>

using namespace std;

typedef long long ll;

int d[1<<20];
int p[1<<20][2];
ll s[1<<20];
int b[1<<20];

int n, q;

void update(int w) {
    if (d[w] == 0) return;
    if (b[w]&(1<<(d[w]-1))) {
        swap(p[w][0],p[w][1]);
        b[w] ^= (1<<d[w]);
    }
    b[p[w][0]] ^= b[w];
    b[p[w][1]] ^= b[w];
    b[w] = 0;
}

void setVal(int w, int x, int k) {
    if (d[w] == 0) {
        s[w] = x;
    } else {
        update(w);
        if ((k-1)&(1<<(d[w]-1))) {
            setVal(p[w][1],x,k);
        } else {
            setVal(p[w][0],x,k);
        }
        s[w] = s[2*w]+s[2*w+1];
    }
}

ll getSum(int w, int a, int b, int x, int y) {
    update(w);
    if (x >= a && y <= b) return s[w];
    if (y < a || x > b) return 0;
    ll s = 0;
    int h = (y-x+1)/2;
    s += getSum(p[w][0],a,b,x,x+h-1);
    s += getSum(p[w][1],a,b,x+h,y);
    return s;
}

void dump() {
    return;
    cout << "dump:\n";
    for (int i = 1; i <= (1<<(n+1))-1; i++) {
        cout << i << " " << d[i] << " " << s[i] << " " << p[i][0] << " " << p[i][1] << " " << b[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    d[1] = n;
    for (int i = 1; i <= (1<<(n+1))-1; i++) {
        if (d[i] == 0) {
            cin >> s[i];
        } else {
            p[i][0] = 2*i;
            d[2*i] = d[i]-1;
            p[i][1] = 2*i+1;
            d[2*i+1] = d[i]-1;
        }
    }
    for (int i = (1<<n)-1; i >= 1; i--) {
        s[i] = s[2*i]+s[2*i+1];
    }
    for (int i = 1; i <= q; i++) {
        dump();
        int t;
        cin >> t;
        if (t == 1) {
            int k, x;
            cin >> k >> x;
            setVal(1,x,k);
        }
        if (t == 2) {
            int k;
            cin >> k;
            for (int i = 0; i < k; i++) b[1] ^= (1<<i);
        }
        if (t == 3) {
            int k;
            cin >> k;
            b[1] ^= (1<<k);
        }
        if (t == 4) {
            int a, b;
            cin >> a >> b;
            cout << getSum(1,a,b,1,1<<n) << "\n";
        }
    }
    dump();
}
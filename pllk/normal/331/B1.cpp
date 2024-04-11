#include <iostream>

#define N (1<<18)

using namespace std;

int p[2*N];

int muuta(int k, int a) {
    k += N;
    p[k] = a;
    k /= 2;
    while (k >= 1) {
        p[k] = p[2*k]+p[2*k+1];
        k /= 2;
    }
}

int haku(int a, int b) {
    a += N;
    b += N;
    int t = 0;
    while (a <= b) {
        if (a%2 == 1) {
            t += p[a];
            a++;
        }
        if (b%2 == 0) {
            t += p[b];
            b--;
        }
        a /= 2;
        b /= 2;
    }
    return t;
}

int n;
int d[200000];
int e[200000];
int q;

void tutki(int i) {
    if (i == -1 || i == n-1) return;
    if (d[i] > d[i+1]) muuta(i, 1);
    if (d[i] < d[i+1]) muuta(i, 0);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        e[i] = a;
        a--;
        d[a] = i;
    }
    for (int i = 0; i < n-1; i++) {
        if (d[i] > d[i+1]) muuta(i, 1);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b--; c--;
        /*for (int i = 0; i < n; i++) cout << d[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++) cout << e[i] << " ";
        cout << endl;*/
        if (a == 1) {
            cout << (haku(b, c-1)+1) << endl;
        } else {
            int bb = e[b]-1;
            int cc = e[c]-1;
            int h;
            h = e[b]; e[b] = e[c]; e[c] = h;
            h = d[bb]; d[bb] = d[cc]; d[cc] = h;
            tutki(bb-1);
            tutki(bb);
            tutki(cc-1);
            tutki(cc);
        }
    }
}
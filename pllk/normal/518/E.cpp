#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int a[101010];
#define A 1060000001

void virhe() {
    cout << "Incorrect sequence\n";
    exit(0);
}

void tee(int x1, int x2, int i1, int i2, vector<int> v) {
    if (x2-x1-1 < (i2-i1)/k-1) virhe();
    if (x1 >= 0) {
        int x = x1;
        for (int i = i1+k; i <= i2-k; i += k) {
            x++;
            a[i] = x;
        }
        return;
    } else if (x2 <= 0) {
        int x = x2;
        for (int i = i2-k; i >= i1+k; i -= k) {
            x--;
            a[i] = x;
        }
        return;
    }
    vector<int> u;
    u.push_back(0);
    for (int i = 1; ; i++) {
        if (u.size() >= v.size()) break;
        if (i < x2) u.push_back(i);
        if (-i > x1) u.push_back(-i);
    }
    sort(u.begin(), u.end());
    int c = 0;
    for (int i = i1+k; i <= i2-k; i += k) {
        a[i] = u[c];
        c++;
    }
}

void laske(int s) {
    vector<int> v;
    int x1 = -A;
    int i1 = s-k, i3;
    for (int i = s; i < n; i += k) {
        if (a[i] == A) {
            v.push_back(i);
            i3 = i;
        } else {
            int x2 = a[i];
            if (x2 <= x1) virhe();
            if (v.size() > 0) tee(x1, x2, i1, i, v);
            x1 = a[i];
            i1 = i;
            v.clear();
        }
    }
    if (v.size() > 0) tee(x1, A, i1, i3+k, v);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        if (x == "?") a[i] = A;
        else a[i] = atoi(x.c_str());
    }
    for (int i = 0; i < k; i++) laske(i);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}
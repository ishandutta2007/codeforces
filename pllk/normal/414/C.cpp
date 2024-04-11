#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int n, m;
int a[2000000];
int b;

#define N (1<<20)
int p[N];

int summa(int a, int b) {
    int s = 0;
    while (b > 0) {
        s += p[b];
        b -= b&(-b);
    }
    return s;
}

void lisaa(int k, int x) {
    while (k <= (1<<20)) {
        p[k] += x;
        k += (k&-k);
    }
}

/*void lisaa(int k, int x) {
    k += N;
    p[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = p[2*k]+p[2*k+1];
    }
}

int summa(int a, int b) {
    a += N; b += N;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s += p[a++];
        if (b%2 == 0) s += p[b--];
        a /= 2; b /= 2;
    }
    return s;
}*/

ll d[30][2];

unordered_set<int> a1;
vector<int> a2;
unordered_map<int, int> a3;

void pakkaa() {
    for (int i = 0; i < b; i++) {
        if (a1.count(a[i])) continue;
        a1.insert(a[i]);
        a2.push_back(a[i]);
    }
    sort(a2.begin(), a2.end());
    int c = 0;
    for (int i = 0; i < a2.size(); i++) {
        c++;
        a3[a2[i]] = c;
    }
    for (int i = 0; i < b; i++) {
        a[i] = a3[a[i]];
    }
}

void laske(int t, int q) {
    ll z = (t/2)*(t/2);
    for (int i = 0; i < b; i += t) {
        ll c = 0;
        for (int j = i; j < i+t/2; j++) {
            lisaa(a[j], 1);
        }
        for (int j = i+t/2; j < i+t; j++) {
            c += summa(0, a[j]-1);
        }
        d[q][1] += c;
        //d[q][0] += z-c;
        for (int j = i; j < i+t/2; j++) {
            lisaa(a[j], -1);
        }
        c = 0;
        for (int j = i+t/2; j < i+t; j++) {
            lisaa(a[j], 1);
        }
        for (int j = i; j < i+t/2; j++) {
            c += summa(0, a[j]-1);
        }
        d[q][0] += c;
        //d[q][0] += z-c;
        for (int j = i+t/2; j < i+t; j++) {
            lisaa(a[j], -1);
        }
    }
}

int e[30];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    b = (1<<n);
    int j = 0;
    for (int i = 0; i < b; i++) {
        cin >> a[i];
    }
    pakkaa();
    for (int i = 1; i <= n; i++) {
        laske(1<<i, i);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) e[j]++;
        ll t = 0;
        for (int j = 1; j <= n; j++) {
            t += d[j][e[j]%2];
        }
        cout << t << endl;
    }
}
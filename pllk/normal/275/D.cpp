#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

int n;
int a, b;

vector<int> p[100000];
int v[100000];

ll my[100000];
ll ma[100000];
bool va[100000];

ll alas(int k, int s);

ll ylos(int k, int s) {
    if (va[k]) return my[k];
    ll y = 0;
    ll a = 0;
    for (int i = 0; i < p[k].size(); i++) {
        if (p[k][i] == s) continue;
        y = max(y, ylos(p[k][i], k));
        a = max(a, alas(p[k][i], k));
    }
    ll m = v[k]+y-a;
    if (m > 0) a += m;
    else y += (-m);
    va[k] = true;
    my[k] = y;
    ma[k] = a;
    return y;
}

ll alas(int k, int s) {
    if (va[k]) return ma[k];
    ll y = 0;
    ll a = 0;
    for (int i = 0; i < p[k].size(); i++) {
        if (p[k][i] == s) continue;
        y = max(y, ylos(p[k][i], k));
        a = max(a, alas(p[k][i], k));
    }
    ll m = v[k]+y-a;
    if (m > 0) a += m;
    else y += (-m);
    va[k] = true;
    my[k] = y;
    ma[k] = a;
    return a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        p[a-1].push_back(b-1);
        p[b-1].push_back(a-1);
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << (ylos(0,-1) + alas(0,-1)) << endl;
}
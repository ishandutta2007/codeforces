#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int u;
    cin >> u;
    return u;
}

int n;
int r[101010];
int z[101010];

void lol(vector<int> v) {
    if (v.size() == 1) {
        for (int i = 1; i <= n; i++) {
            if (!z[i]) r[v[0]] = i;
        }
        return;
    }
    vector<int> u;
    int k = v.size();
    for (int i = 0; i+1 < k; i += 2) {
        int a = ask(v[i],v[i+1]);
        int b = ask(v[i+1],v[i]);
        if (a > b) {
            r[v[i]] = a;
            z[a] = 1;
            u.push_back(v[i+1]);
        } else {
            r[v[i+1]] = b;
            z[b] = 1;
            u.push_back(v[i]);
        }
    }
    if (k%2 == 1) u.push_back(v.back());
    lol(u);
}

int main() {
    vector<int> v;
    cin >> n;
    for (int i = 1; i <= n; i++) v.push_back(i);
    lol(v);
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << r[i] << " ";
    cout << endl;
}
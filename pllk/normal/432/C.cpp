#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[101010];
vector<int> pp;

int n;
vector<pair<int,int>> v;
int x[101010];
int y[101010];

vector<pair<int,int>> q;

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 2; i < 100000; i++) {
        if (p[i]) continue;
        for (int j = 2*i; j < 100000; j += i) {
            p[j] = 1;
        }
    }
    for (int i = 2; i < 100000; i++) {
        if (!p[i]) pp.push_back(i);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(make_pair(a,i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        x[v[i].second] = i;
        y[i] = v[i].second;
    }
    for (int i = 0; i < n; i++) {
        int k = y[i];
        while (k > i) {
            int u = 0;
            for (int b = pp.size(); b >= 1; b /= 2) {
                while (u+b < pp.size() && k-(pp[u+b]-1) >= i) u += b;
            }
            int z = k-(pp[u]-1);
            q.push_back(make_pair(z+1,k+1));
            y[x[z]] = k;
            x[k] = x[z];
            k = z;
        }
    }
    cout << q.size() << endl;
    for (int i = 0; i < q.size(); i++) {
        cout << q[i].first << " " << q[i].second << endl;
    }
}
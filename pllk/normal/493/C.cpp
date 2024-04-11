#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int,int>> v;

int a, b;
int pa, pb;
int ca, cb;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(make_pair(x,1));
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v.push_back(make_pair(x,2));
    }
    sort(v.begin(), v.end());
    pa = 3*n; pb = 3*m;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == 1) ca++;
        else cb++;
        if (i+1 < v.size() && v[i].first == v[i+1].first) continue;
        a = 2*ca+3*(n-ca);
        b = 2*cb+3*(m-cb);
        if (a-b > pa-pb || (a-b == pa-pb && a > pa)) {pa = a; pb = b;}
    }
    cout << pa << ":" << pb << "\n";
}
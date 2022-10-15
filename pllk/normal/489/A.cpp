#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int t[3333];
vector<pair<int,int>> x;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) {
        int v = i;
        for (int j = i; j < n; j++) {
            if (t[j] < t[v]) v = j;
        }
        if (v == i) continue;
        swap(t[i], t[v]);
        x.push_back(make_pair(i,v));
    }
    cout << x.size() << "\n";
    for (int i = 0; i < x.size(); i++) {
        cout << x[i].first << " " << x[i].second << "\n";
    }
}
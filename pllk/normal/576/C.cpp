#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<pair<pair<int,int>,pair<int,int>>> v;


int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int k = y/1000;
        if (k%2 == 0) x = -x;
        v.push_back(make_pair(make_pair(k,x),make_pair(y,i+1)));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i].second.second << " ";
    }
    cout << "\n";
}
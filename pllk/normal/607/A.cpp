#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> v;
int d[1111111];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a+1,b));
    }
    sort(v.begin(), v.end());
    int j = -1;
    int p = 0;
    for (int i = 1; i <= 1000001; i++) {
        if (j+1 < v.size() && v[j+1].first == i) {
            j++;
            d[i] = 1+d[max(0,i-v[j].second-1)];
            p = max(p,d[i]);
        } else {
            d[i] = d[i-1];
        }
    }
    cout << n-p << "\n";
}
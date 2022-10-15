#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int s;
vector<pair<int,int>> v;

int main() {
    cin >> n >> m;
    if (n < m) {swap(n, m); s = 1;}
    if (n == m && n > 3) {
        v.push_back(make_pair(n-1,0));
        v.push_back(make_pair(0,n));
        v.push_back(make_pair(n,0));
        v.push_back(make_pair(0,n-1));
    } else if (m == 0) {
        v.push_back(make_pair(n-1,0));
        v.push_back(make_pair(0,0));
        v.push_back(make_pair(n,0));
        v.push_back(make_pair(1,0));
    }
    else if (m == 1 || m == 2 || m == 3) {
        v.push_back(make_pair(n,0));
        v.push_back(make_pair(0,m));
        v.push_back(make_pair(n,m));
        v.push_back(make_pair(0,0));
    }
    else if (m > 3) {
        v.push_back(make_pair(n,1));
        v.push_back(make_pair(0,m));
        v.push_back(make_pair(n,0));
        v.push_back(make_pair(0,m-1));
    }
    for (int i = 0; i < 4; i++) {
        if (s) cout << v[i].second << " "<< v[i].first << "\n";
        else cout << v[i].first << " "<< v[i].second << "\n";
    }
}
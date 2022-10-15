#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<pair<int,int>> t[101010];
int c;

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int y = i+1;
            int x = (i%2) ? (j+1) : (m-j);
            t[c].push_back(make_pair(y,x));
            if (c < k-1 && t[c].size() == 2) c++;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << t[i].size() << " ";
        for (int j = 0; j < t[i].size(); j++) {
            cout << t[i][j].first << " " << t[i][j].second << " ";
        }
        cout << "\n";
    }
}
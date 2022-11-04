#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
const unsigned long long INF = 10000000000000000;
const int Y = 1000000;
//const long long m = 1000000007;
bool visited[500];
vector<pair<int, int>>ans;
vector<string>sup;
int n, m;
bool eq(int i, int i1) {
    for (int j = 0; j < m; ++j) {
        if (sup[i][j] != sup[i1][m - 1 - j])return false;
    }
    return true;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        sup.push_back(tmp);
    }
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i])continue;
        for (int j = i + 1; j < n; ++j) {
            if (visited[j])continue;
            if (eq(i, j)) {
                visited[i] = visited[j] = true;
                l += 2 * m;
                ans.push_back({ i,j });
                break;
            }
        }
    }
    int mid = -1;
    for (int i = 0; i < n; ++i) {
        if (visited[i])continue;
        if (eq(i, i)) {
            mid = i;
            l += m;
            break;
        }
    }
    cout << l << "\n";
    string h = "";
    for (auto x : ans) {
        cout << sup[x.first];
        h += sup[x.first];
    }
    if (mid != -1)cout << sup[mid];
    for (int i = (int)h.size() - 1; i >= 0; --i)cout << h[i];
    return 0;
}
/* Thu Feb 06 2020 12:04:32 GMT+0300 (MSK) */
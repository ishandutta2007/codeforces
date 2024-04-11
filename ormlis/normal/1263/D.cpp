#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;

int n;
const int INF = 1e9 * 2;
int dsu[26];
vector<int> ans[150001];
int used[26];
void make_dsu(int i) {
    dsu[i] = i;
}

void init_dsu() {
    range(i, 26) {
        make_dsu(i);
    }
}

int get_dsu(int a) {
    return (dsu[a] == a) ? a : dsu[a] = get_dsu(dsu[a]);
}

bool Unio(int a, int b) {
    a = get_dsu(a);
    b = get_dsu(b);
    if(rand() % 2) swap(a, b);
    dsu[a] = b;
    ans[b].push_back(a);
    return a == b;
}


void solve() {
    cin >> n;
    init_dsu();
    string s;
    vector<string> arr(n);
    range(i, n) {
        cin >> s;
        arr[i] = s;
        char a = s[0] - 'a';
        used[a] = 1;
        for(int j = 1; j < (int)s.size(); j++) {
            Unio(s[j] - 'a', a);
            used[s[j] - 'a'] = 1;
        }
    }
    vector<int> ans2(26, 0);
    range(i, 26) {
        if (used[i]) {
            ans2[get_dsu(i)] = 1;
        }
    }
    int aa = 0;
    range(i, 26) {
        aa += ans2[i];
    }
    cout << aa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
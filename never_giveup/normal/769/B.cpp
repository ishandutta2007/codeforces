#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

pair<int, int> a[maxn];

int n;

vector<pair<int, int> > answer;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(a + 1, a + n);
    reverse(a + 1, a + n);
    int r = 1;
    for (int l = 0; l < n; l++){
        if (l == r){
            cout << -1;
            return 0;
        }
        while (a[l].first > 0 && r < n)
            answer.push_back(make_pair(a[l].second + 1, a[r].second + 1)), a[l].first--, r++;
        if (r == n)
            break;
    }
    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i].first << ' ' << answer[i].second << '\n';
}
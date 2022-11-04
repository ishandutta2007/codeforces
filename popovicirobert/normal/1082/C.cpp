#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

vector <ll> arr[MAXN + 1];
int id[MAXN + 1];

bool cmp(int a, int b) {
    return arr[a].size() > arr[b].size();
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m, s, r;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> s >> r;
        arr[s].push_back(r);
    }
    for(i = 1; i <= m; i++) {
        sort(arr[i].begin(), arr[i].end(), greater<ll>());
        for(j = 0; j < arr[i].size(); j++) {
            if(j > 0)
                arr[i][j] += arr[i][j - 1];
        }
        id[i] = i;
    }
    sort(id + 1, id + m + 1, cmp);
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        vector <ll> aux;
        for(j = 1; j <= n; j++) {
            if(arr[id[j]].size() < i) {
                break;
            }
            aux.push_back(arr[id[j]][i - 1]);
        }
        sort(aux.begin(), aux.end(), greater<ll>());
        ll cur = 0;
        for(j = 0; j < aux.size(); j++) {
            /*if(i == 2) {
                cerr << aux[j] << " ";
            }
            cerr << "\n";*/
            if(aux[j] < 0) {
                break;
            }
            cur += aux[j];
        }
        ans = max(ans, cur);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const ld EPS = 1e-9;

const ll llinf = 1e18 + 100;

const int maxn = 1e5 + 100, inf = 1e9 + 100;

int n, C, D;

pair<int, int> a[2][maxn];

int sz[2];

int ez[2];

int pmax[2][maxn];

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
	    #ifndef STR
	    //ifstream cin("a.in");
	    //ofstream cout("a.out");
	    //freopen("a.in", "r", stdin);
	    //freopen("a.out", "w", stdout);
    	    #endif // STR
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> C >> D;
    for (int i = 0; i < n; i++){
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'C')
            a[0][sz[0]] = make_pair(y, x), sz[0]++;
        else
            a[1][sz[1]] = make_pair(y, x), sz[1]++;
    }
    sort(a[0], a[0] + sz[0]);
    sort(a[1], a[1] + sz[1]);
    int answer = 0;
    if (sz[0] > 0 && sz[1] > 0){
        int x = 0, y = 0;
        ez[0] = sz[0] - 1;
        for (int i = 0; i < sz[0]; i++)
            if (a[0][i].first > C){
                ez[0] = i - 1;
                break;
            }
            else
                x = max(x, a[0][i].second);
        ez[1] = sz[1] - 1;
        for (int i = 0; i < sz[1]; i++)
            if (a[1][i].first > D){
                ez[1] = i - 1;
                break;
            }
            else
                y = max(y, a[1][i].second);
        if (ez[0] >= 0 && ez[1] >= 0)
            answer = x + y;
    }
    pmax[0][0] = a[0][0].second;
    pmax[1][0] = a[1][0].second;
    for (int i = 1; i < sz[0]; i++)
        pmax[0][i] = max(pmax[0][i - 1], a[0][i].second);
    for (int i = 1; i < sz[1]; i++)
        pmax[1][i] = max(pmax[1][i - 1], a[1][i].second);
    int it = -1;
    int val = 0;
    for (int i = sz[0] - 1; i >= 0; i--){
        while (it < i - 1 && a[0][it + 1].first + a[0][i].first <= C)
            it++;
        it = min(it, i - 1);
        if (it >= 0)
            answer = max(answer, pmax[0][it] + a[0][i].second);
    }
    it = -1;
    val = 0;
    for (int i = sz[1] - 1; i >= 0; i--){
        while (it < i - 1 && a[1][it + 1].first + a[1][i].first <= D)
            it++;
        it = min(it, i - 1);
        if (it >= 0)
            answer = max(answer, pmax[1][it] + a[1][i].second);
    }
    cout << answer;
}
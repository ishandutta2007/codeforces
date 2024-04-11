#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e3 + 100, inf = 1e9 + 100;

int N, n;

bool his[maxn];

int q[2 * maxn];

int g(int x){
    return x + 1000;
}

int r(int x){
    return x - 1000;
}

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("gift.in");
    //ofstream cout("gift.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> N >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        his[x] = 1;
    }
    for (int i = 0; i < 2 * maxn; i++)
        q[i] = inf;
    set<pair<int, int> > w;
    for (int i = 0; i <= 1000; i++)
        if (his[i])
            q[g(i - N)] = 1, w.insert(make_pair(1, g(i - N)));
    while (!w.empty()){
        int gi = w.begin()->second;
        w.erase(w.begin());
        int d = q[gi] + 1;
        int ri = r(gi);
        for (int i = 0; i <= 1000; i++)
        if (his[i]){
            int to = ri + i - N;
            int gto = g(to);
            if (gto >= 0 && gto <= 2000 && q[gto] > d)
                w.erase(make_pair(q[gto], gto)),
                q[gto] = d,
                w.insert(make_pair(q[gto], gto));
        }
    }
    if (q[g(0)] == inf)
        cout << -1;
    else
        cout << q[g(0)];
}
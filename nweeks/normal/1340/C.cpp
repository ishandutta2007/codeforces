#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN =  1e4;
const int MAXT = 1000;
bool seen[MAXN][MAXT];

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int len_route, nb_arrets;
    cin >> len_route >> nb_arrets;

    vector<int> arrets(nb_arrets);
    for (auto &v : arrets)
        cin >> v;
    sort(arrets.begin(), arrets.end());
    int g, r;
    cin >> g >> r;

    vector<queue<int> > Q(g);
    queue<pair<int, int> > nxt_q;
    Q[0].push(0);
    int tot_time(0);
    while (!Q[0].empty())
    {
        for (int t(0); t < g; ++t)
        {
            while (!Q[t].empty())
            {
                int u = Q[t].front(); Q[t].pop();
                if (u == nb_arrets-1)
                {
                    cout << tot_time << endl;
                    return 0;
                }
                if (seen[u][t])
                    continue ;
                seen[u][t] = true;
                for (int nxt(-1+u); nxt <= 1+u; nxt += 2)
                    if (0<= nxt and nxt < nb_arrets)
                    {
                        int dis = abs(arrets[nxt] - arrets[u]);
                        if (t + dis > g) continue;
                        if (t + dis == g)
                            nxt_q.push(make_pair(nxt, tot_time+dis));
                        else
                            Q[t+dis].push(nxt);
                    }
            }
            tot_time++;
        }
        while (!nxt_q.empty())
        {
            auto [u, t] = nxt_q.front(); nxt_q.pop();
            if (u == nb_arrets-1)
            {
                cout << t <<endl;
                return 0;
            }
            Q[0].push(u);
        }
        tot_time += r;
    }
    cout << -1 << endl;
    return 0;       
}
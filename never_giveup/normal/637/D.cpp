#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6;

int q[maxn], fin, razbeg, jump, n;

pair<int, int> ans[maxn];

int sz = 0;

int main(){
    cin >> n >> fin >> razbeg >> jump;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    q[n] = 0;
    q[n + 1] = fin;
    n += 2;
    sort(q, q + n);
    int i = 0, now = 0;
    while (i < n - 1)
        if (i == n - 2){
            if (fin - now > 0)
                ans[sz] = make_pair(0, fin - now), sz++;
            break;
        }
        else
            if (q[i + 1] - 1 - now < razbeg){
                cout << "IMPOSSIBLE";
                return 0;
            }
            else{
                if (q[i + 1] - 1 - now > 0)
                    ans[sz] = make_pair(0, q[i + 1] - 1 - now), sz++;
                now = q[i + 1] - 1;
                while (1){
                    i++;
                    if (q[i] + 1 - now > jump){
                        cout << "IMPOSSIBLE";
                        return 0;
                    }
                    if (i == n - 2){
                        ans[sz] = make_pair(1, q[i] + 1 - now), sz++, now = q[i] + 1;
                        break;
                    }
                    else
                        if (q[i + 1] - 1 - q[i] - 1 >= razbeg){
                            ans[sz] = make_pair(1, q[i] + 1 - now), sz++, now = q[i] + 1;
                            break;
                        }
                }
            }
    for (int i = 0; i < sz; i++)
        if (ans[i].first == 0)
            cout << "RUN " << ans[i].second << '\n';
        else
            cout << "JUMP " << ans[i].second << '\n';
}
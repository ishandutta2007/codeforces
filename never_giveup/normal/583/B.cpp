#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int n, v[1000], q[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i], v[i] = 0;
    int it = 0, l = 1, ans = 0, now = 0;
    while (now < n){
        bool f = 0;
        if (l == 0){
            for (int i = it; i >= 0; i--)
                if (v[i] == 0 && q[i] <= now){
                    now++, v[i] = 1, it = i, f = 1;
                    continue;
                }
        }
        else{
            for (int i = it; i < n; i++)
                if (v[i] == 0 && q[i] <= now){
                    now++, v[i] = 1, it = i, f = 1;
                    continue;
                }
        }
        if (f == 0)
            l = (l + 1) % 2, ans++;
    }
    cout << ans;
}
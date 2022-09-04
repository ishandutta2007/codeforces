#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

const ll inf = 1e18 + 100;

int n, m, k;

pair<int, int> dt[maxn];

pair<pair<ll, int>, vector<int> > a[2 * maxn], b[2 * maxn];

bool was[maxn][4][2];

ll ans[maxn];

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
        cin >> dt[i].first >> dt[i].second, a[dt[i].first - dt[i].second + maxn].second.push_back(i), b[dt[i].first + dt[i].second].second.push_back(i);
    for (int i = 0; i < 2 * maxn; i++)
        a[i].first.first = inf, b[i].first.first = inf;
    int xnow = 0, ynow = 0;
    int from = 1;
    ll time = 0;
    while(1){
        from ^= 1;
        int add;
        if (from == 0){
            if (a[xnow - ynow + maxn].first.first > time)
                a[xnow - ynow + maxn].first = make_pair(time, (ynow == 0 ? 0 : (ynow == m ? 2 : (xnow == 0 ? 1 : 3))));
            if (ynow == 0 || xnow == 0)
                add = min(n - xnow, m - ynow), xnow += add, ynow += add, time += add;
            else
                add = min(xnow, ynow), xnow -= add, ynow -= add, time += add;
        }
        else{
            if (b[xnow + ynow].first.first > time)
                b[xnow + ynow].first = make_pair(time, (ynow == 0 ? 0 : (ynow == m ? 2 : (xnow == 0 ? 1 : 3))));
            if (xnow == 0 || ynow == m)
                add = min(n - xnow, ynow), xnow += add, ynow -= add, time += add;
            else
                add = min(xnow, m - ynow), xnow -= add, ynow += add, time += add;
        }
        if ((xnow == 0 || xnow == n) && (ynow == 0 || ynow == m))
            break;
        int where;
        if (xnow == 0)
            where = 1;
        if (ynow == 0)
            where = 0;
        if (xnow == n)
            where = 3;
        if (ynow == m)
            where = 2;
        int ind;
        if (xnow == 0 || xnow == n)
            ind = ynow;
        else
            ind = xnow;
        if (was[ind][where][from])
            break;
        was[ind][where][from] = 1;
    }
    for (int i = 0; i < maxn; i++)
        ans[i] = inf;
    for (int i = 0; i < 2 * maxn; i++){
        if (a[i].first.first != inf){
            for (int j = 0; j < a[i].second.size(); j++)
                if (a[i].first.second == 0)
                    ans[a[i].second[j]] = min(ans[a[i].second[j]], a[i].first.first + dt[a[i].second[j]].second);
                else
                if (a[i].first.second == 2)
                    ans[a[i].second[j]] = min(ans[a[i].second[j]], a[i].first.first + m - dt[a[i].second[j]].second);
                else
                if (a[i].first.second == 1)
                    ans[a[i].second[j]] = min(ans[a[i].second[j]], a[i].first.first + dt[a[i].second[j]].first);
                else
                    ans[a[i].second[j]] = min(ans[a[i].second[j]], a[i].first.first + n - dt[a[i].second[j]].first);
        }
        if (b[i].first.first != inf){
            for (int j = 0; j < b[i].second.size(); j++)
                if (b[i].first.second == 1)
                    ans[b[i].second[j]] = min(ans[b[i].second[j]], b[i].first.first + dt[b[i].second[j]].first);
                else
                if (b[i].first.second == 3)
                    ans[b[i].second[j]] = min(ans[b[i].second[j]], b[i].first.first + n - dt[b[i].second[j]].first);
                else
                if (b[i].first.second == 0)
                    ans[b[i].second[j]] = min(ans[b[i].second[j]], b[i].first.first + dt[b[i].second[j]].second);
                else
                    ans[b[i].second[j]] = min(ans[b[i].second[j]], b[i].first.first + m - dt[b[i].second[j]].second);
        }
    }
    for (int i = 0; i < k; i++)
        cout << (ans[i] == inf ? -1 : ans[i]) << '\n';
}
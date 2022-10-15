#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    ll no;
    ll dist;
};
vector<node> all;
node h;
ll n, m, i, j, k;
int cmp(node a, node b) { return (a.dist < b.dist); }
int main()
{
    cin >> n >> k;
    ll used[n + 1], par[n + 1];
    for (i = 1; i <= n; i++)
    {
        used[i] = 0;
        cin >> h.dist;
        h.no = i;
        all.push_back(h);
    }
    sort(all.begin(), all.end(), cmp);
    if ((all[0].dist > 0) or (all[1].dist == 0))
    {
        cout << -1;
        return 0;
    }
    for (i = 1; i < n; i++)
        if (all[i].dist - all[i - 1].dist > 1)
        {
            cout << -1;
            return 0;
        }
    j = 0;
    for (i = 1; i < n; i++)
    {
        if (all[i].dist - all[i - 1].dist > 0)
            j = i - 1;
        if (((used[all[j].no] >= k-1)and(j!=0))or(used[all[j].no] >= k))
            {
                j--;
                if ((all[j].dist < all[i].dist-1)or(j==-1))
                {
                    cout << -1;
                    return 0;
                }
        }
        par[all[i].no] = all[j].no;
        used[all[j].no]++;
        //cout<<i<<' '<<j<<endl;
    }
    cout << n - 1 << endl;
    for (i = 1; i < n; i++)
        cout << par[all[i].no] << ' ' << all[i].no << endl;
}
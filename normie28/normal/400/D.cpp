
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
const int DL = 503;
const int DL2 = 100010;
int parent[DL2], rankval[DL2], d[DL][DL], type[DL2];
int getroot(int v);
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int i, j, k, n, m, kl = 0, u, v, x, u1, v1, p;
    cin >> n >> m >> k;
    for (i = 0; i < k; i++)
    {
    	cin>>x;
        for (j = 0; j < x; j++)
        {
            kl++;
            parent[kl - 1] = -1;
            rankval[kl - 1] = 1;
            type[kl - 1] = i;
 
        }
    }
    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            d[i][j] = -1;
    for (i = 0; i < k; i++) d[i][i] = 0;
    for (i = 0; i < m; i++)
    {
    	cin>>u>>v>>x;
        u--;
        v--;
        if ((d[type[u]][type[v]] == -1) || (d[type[u]][type[v]] > x))
            d[type[u]][type[v]] = x;
        if ((d[type[v]][type[u]] == -1) || (d[type[v]][type[u]] > x))
            d[type[v]][type[u]] = x;
        if (x == 0)
        {
            u1 = getroot(u);
            v1 = getroot(v);
            if (u1 != v1)
            {
                if (rankval[u1] > rankval[v1])
                    parent[v1] = u1;
                else if (rankval[u1] < rankval[v1])
                    parent[u1] = v1;
                else
                {
                    parent[v1] = u1;
                    rankval[u1]++;
                }
            }
        }
    }
    for (i = 1; i < n; i++)
        if ((type[i] == type[i - 1]) && (getroot(i) != getroot(i - 1)))
        {
        	cout<<"No"<<endl;
            return 0;
        }
    for (p = 0; p < k; p++)
        for (i = 0; i < k; i++)
            for (j = 0; j < k; j++)
                if ((d[i][p] != -1) && (d[p][j] != -1) && ((d[i][p] + d[p][j] < d[i][j]) || (d[i][j] == -1)))
                    d[i][j] = d[i][p] + d[p][j];
        	cout<<"Yes"<<endl;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k - 1; j++)
            cout<<d[i][j]<<' ';
        cout<<d[i][k - 1]<<endl;
    }
}
 
int getroot(int v)
{
    if (parent[v] == -1)
        return v;
    int val = getroot(parent[v]);
    parent[v] = val;
    return val;
}
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define INF 2000000000
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m, k;
	cin >> n >> m;
	std::vector<std::vector<std::pair<int, int> > > adj(n);
	int a, b, c;
	print(n);
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c; a--; b--;
		adj[a].pb(mp(b, c)); adj[b].pb(mp(a, c));
	}
	std::vector<std::vector<int> > notfree(n);
	std::vector<std::vector<int> > atfree(n);
	std::vector<int> siz(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> siz[i];
		if (siz[i] != 0)
		{
			notfree[i].resize(siz[i]);
			atfree[i].resize(siz[i]);
			for (int j = 0; j < siz[i]; ++j)
			{
				cin >> notfree[i][j];
			}
			atfree[i][siz[i]-1] = notfree[i][siz[i]-1]+1;
			for (int j = siz[i]-2; j >= 0; --j)
			{
				if(notfree[i][j] == (notfree[i][j+1]-1))
					atfree[i][j] = atfree[i][j+1];
				else
					atfree[i][j] = notfree[i][j]+1;
			}
		}
	}
	priority_queue< std::pair<int, int>, vector<std::pair<int, int> > , greater<std::pair<int, int> > > pq;
    vector<int> tim(n, INF);
    pq.push(mp(0, 0));
    int src = 0;

    tim[src] = 0;
    int O = 0;
   	while(O < siz[src] && notfree[src][O] == tim[src]) {
		tim[src]++;
	    O++;
    }
    std::pair<int, int> p1;
    while (!pq.empty())
    {
        p1 = pq.top();
        int u = p1.second;
        int t1 = p1.first;
        pq.pop();
        for (std::pair<int, int> p : adj[u])
        {
            int v = p.first;
            int weight = p.second;
            int timetaken = tim[u] + weight;
            if (v == n-1 && tim[v] > timetaken)
            	tim[v] = timetaken;

            ///extra time
            int o = lower_bound(notfree[v].begin(), notfree[v].end(), tim[u]+weight) - notfree[v].begin();
            if(o < siz[v] && notfree[v][o] == timetaken) {
            	timetaken = atfree[v][o];
            }
            if (tim[v] > timetaken)
            {
                tim[v] = timetaken;
                pq.push(make_pair(timetaken, v));
            }
        }
    }
    cout<<((tim[n-1] == INF)?(-1):(tim[n-1]));
}
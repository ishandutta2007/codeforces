#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) (int)(a).size()


#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));

typedef long long ll;

const int N = 100005;

template<typename T> // max path type
class Heap
{
public:
    //vector<int> vec, pos;
    //vector<T> val;
    int vec[N], pos[N];
    T val[N];
    int siz;

    Heap() //number of vertexes
    {
        siz = 0;
        for (int i = 0; i < N; i++)
            pos[i] = -1;
        //vec.clear();
        //val.assign(sz, -1);
        //pos.assign(sz, -1);
    }

    void siftDown(int v)
    {
        while (true)
        {
            int u = (v << 1) | 1;
            if (u + 1 < siz && val[vec[u + 1]] < val[vec[u]])
                ++u;
            if (u < siz && val[vec[u]] < val[vec[v]])
            {
                swap(pos[vec[u]], pos[vec[v]]);
                swap(vec[u], vec[v]);
                v = u;
            }
            else
                break;
        }
    }

    void siftUp(int v)
    {
        while (v)
        {
            int u = ((v - 1) >> 1);
            if (val[vec[u]] > val[vec[v]])
            {
                swap(pos[vec[u]], pos[vec[v]]);
                swap(vec[u], vec[v]);
                v = u;
            }
            else
                break;
        }
    }

    Heap(vector<T> a)
    {
        vec = a;
        for (int i = siz - 1; i >= 0; i--)
            siftDown(i);
    }

    T best_vertex()
    {
        return vec[0];
    }

    void push(int v, T value)
    {
        if (pos[v] == -1)
        {
            vec[siz++] = v;
            pos[v] = siz - 1;
        }
        val[v] = value;
        siftUp(pos[v]);
    }

    void pop()
    {
        swap(vec[0], vec[siz - 1]);
        swap(pos[vec[0]], pos[vec[siz - 1]]);
        pos[vec[siz - 1]] = -1;
        siz--;
        siftDown(0);
    }

    int size()
    {
        return siz;
    }
};

const ll INF = 1e18;

vector<int> g[N], w[N];
ll d[N];
int p[N];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }
    Heap<ll> q;
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;
    q.push(0, 0);
    while (q.size())
    {
        int v = q.best_vertex();
        q.pop();
        for (int i = 0; i < sz(g[v]); i++)
        {
            int u = g[v][i];
            ll l = w[v][i];
            if (d[u] > d[v] + l)
            {
                d[u] = d[v] + l;
                p[u] = v;
                q.push(u, d[u]);
            }
        }
    }
    vector<int> ans;
    if (d[n - 1] == INF)
    {
        cout << -1 << endl;
        return 1;
    }
    int v = n - 1;
    while (v)
    {
        ans.push_back(v);
        v = p[v];
    }
    cout << "1 ";
    reverse(ans.begin(), ans.end());
    for (int u : ans)
        cout << u + 1 << ' ';
    cout << endl;
    return 1;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    while (TET--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}
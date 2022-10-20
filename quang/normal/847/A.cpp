#include <bits/stdc++.h>
#define FOR(i, j, k) for (int i = j; i <= k; i ++)
#define FORD(i, j, k) for (int i = j; i >= k; i --)
#define mn 200005
#define maxC 1000000007
#define base 100007
#define F first
#define S second

using namespace std;
int n, l[mn], r[mn], s = 0;
stack<int> st;
bool mark[mn];

void setup()
{
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> l[i] >> r[i];
        if (!l[i])
            s = i;
    }

    mark[s] = true;
    st.push(s);

    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        while(r[u])
            u = r[u];
        FOR(v, 1, n)
        if (!l[v] && !mark[v])
        {
            l[v] = u;
            r[u] = v;
            mark[v] = true;
            st.push(v);
            break;
        }
    }

    FOR(i, 1, n)
        cout << l[i] << ' ' << r[i] << '\n';
}

void xuly ()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    setup ();
    xuly ();
    return 0;
}
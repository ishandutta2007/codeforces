#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define N 100020
#define G 1000000007LL
using namespace std;
 
long long c[N];
 
int t, d[N], l[N];
bool v[N];
stack<int> s;
vector<int> e[N];
 
long long a, b;
 
inline void tarjan(const int x)
{
    int i;
    int y;
    long long m, k;
 
    for(i = 0, d[x] = l[x] = ++ t, v[x] = true, s.push(x); i < (signed)e[x].size(); i ++)
        if(!d[e[x].at(i)])
        {
            tarjan(e[x].at(i));
            l[x] = min(l[x], l[e[x].at(i)]);
        }
        else
            if(v[e[x].at(i)])
                l[x] = min(l[x], d[e[x].at(i)]);
 
    if(d[x] == l[x])
    {
        m = G;
        k = 1;
        do
        {
            y = s.top();
            s.pop();
 
            if(c[y] == m)
                ++ k;
            if(c[y] < m)
            {
                m = c[y];
                k = 1;
            }
 
            v[y] = false;
        }
        while(x != y);
 
        a += m;
        (b *= k) %= G;
    }
 
    return;
}
 
int main()
{
    int n, m;
    int i;
    int u, v;
 
    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%I64d", &c[i]);
    scanf("%d", &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
    }
 
    for(i = b = 1; i <= n; i ++)
        if(!d[i])
            tarjan(i);
 
    printf("%I64d %I64d\n", a, b);
 
    return 0;
}
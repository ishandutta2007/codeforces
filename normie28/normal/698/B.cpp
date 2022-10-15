#include <bits/stdc++.h>
#define MAXX 200005
using namespace std;
int n,root,par[MAXX],a[MAXX],val[MAXX],ans;
vector<int>v;
int f(int nod)
{
    if(par[nod] == nod)return nod;
    return par[nod] = f(par[nod]);
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        par[i] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == i)continue;
        int x = f(i);
        int y = f(a[i]);
        if(x!=y)
        {
            val[i] = 1;
            par[x] = y;
        }
    }
    root = -1;
    for(int i = 1; i <= n; i++)
    {
        if(!val[i])
        {
            v.push_back(i);
            if(a[i] == i)root = i;
        }
    }
    ans = v.size();
    if(v.size())
    {
        if(root == -1)root = v[0];
        else ans--;
        a[root] = root;
        for(int j = 0 ; j < v.size(); j++)
        {
            if(root == v[j]) continue;
            a[v[j]] = root;
        }
    }
    cout << ans <<endl;
    for(int i = 1; i <= n; i++)cout << a[i] <<" " ;
}
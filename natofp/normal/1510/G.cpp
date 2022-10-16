#include<bits/stdc++.h>
using namespace std;
vector<int> pol[105];
int pre[105];
int post[105];
int subtree[105];
bool odw[105];
vector<int> v;
int l = 0;
int g = 0;
int koniec;
bool parent(int a,int b)
{
    return (pre[a] <= pre[b]) & (post[a] >= post[b]);
}
void dfs1(int a)
{
    pre[a] = l;
    l++;
    for(auto x:pol[a])
    {
        subtree[x] = subtree[a] + 1;
        dfs1(x);
    }
    post[a] = l;
    l++;
}
void dfs2(int a)
{
    v.push_back(a);
    odw[a] = true;
    if(a == koniec)
        return;
    for(auto x:pol[a])
    {
        if(g > 0 && !odw[x] && !parent(x,koniec))
        {
            g--;
            dfs2(x);
            v.push_back(a);
        }
    }
    for(auto x:pol[a])
    {
        if(parent(x,koniec))
        {
            dfs2(x);
            //v.push_back(a);
        }
    }
}
void solve()
{
    int a,b;
    cin>>a>>b;
    for(int x=2;x<=a;x++)
    {
        int c;
        cin>>c;
        pol[c].push_back(x);
    }
    subtree[1] = 1;

    dfs1(1);

    pair<int,int> p = make_pair(1,1);
    for(int x=1;x<=a;x++)
        if(subtree[x] <= b && subtree[x] > p.second)
            p = make_pair(x,subtree[x]);
    b -= p.second;
    g = b;
    koniec = p.first;
    dfs2(1);
    cout<<v.size()-1<<'\n';
    for(auto x:v)
        cout<<x<<" ";
    for(int x=1;x<=a;x++)
    {
        odw[x] = false;
        pol[x].resize(0);
    }
    l = 0;
    v.resize(0);
    cout<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
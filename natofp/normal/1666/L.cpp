#include<bits/stdc++.h>
using namespace std;
bool odw[1000005];
int par[1000005];
int group[1000005];
vector<int> pol[1000005];
int start;
void wypisz(int a)
{
    vector<int> v;
    while(a != -1)
    {
        v.push_back(a);
        a = par[a];
    }
    reverse(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(auto x:v)
        cout<<x<<" ";
    cout<<'\n';
}
void dfs(int a, int b, int c)
{
    odw[a] = true;
    par[a] = b;
    group[a] = c;
    for(auto x:pol[a])
    {
        if(!odw[x])
            dfs(x,a,c);
        else if(x != start && group[x] != group[a])
        {
            cout<<"Possible\n";
            wypisz(x);
            par[x] = a;
            wypisz(x);
            exit(0);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b>>start;
    while(b--)
    {
        int c,d;
        cin>>c>>d;
        pol[c].push_back(d);
    }
    odw[start] = true;
    par[start] = -1;
    for(auto x:pol[start])
    {
        if(odw[x])
        {
            cout<<"Possible\n";
            wypisz(x);
            par[x] = start;
            wypisz(x);
            exit(0);
        }
        dfs(x,start,x);
    }

    cout<<"Impossible\n";
    return 0;
}
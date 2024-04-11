#include <bits/stdc++.h>
using namespace std;
void answer(int x)
{
    cout<<"! ";
    cout<<x<<endl;
    exit(0);
}
pair<int,int> ask(vector<int> x)
{
    cout<<"? ";
    for (auto g : x ) cout<<g<<' ';
    cout<<endl;
    int u,v;
    cin>>u>>v;
    if (u==-1) exit(0);
    return {u,v};
}
int n,m,i,j,k,t,t1,u,v,a,b;
map<int,int> bruh;
vector<int> lmao;
int main()
{
    cin>>n>>m;
    for (i=1;i<=m+1;i++)
    {
        lmao.clear();
    for (j=1;j<=m+1;j++)
    {
        if (j-i) lmao.push_back(j);
    }
    auto g=ask(lmao);
    bruh[g.second]++;
    }
    for (auto g : bruh) answer(m+1-g.second);
}
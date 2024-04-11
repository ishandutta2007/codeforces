#include <bits/stdc++.h>
using namespace std;
vector<int> price;
int n,m,i,j,k,t,t1,u,v,a,b;
struct cmp1
{
    int operator()(int a, int b) const
    {
        if (price[a]-price[b]) return (price[a]>price[b]);
        return (a<b);
    }
};
struct cmp2
{
    int operator()(int a, int b) const
    {
        return (a<b);
    }
};
set<int,cmp1> s1;
set<int,cmp2> s2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    price.push_back(0);
    for (i=1;i<=n;i++)
    {
        cin>>t;
        if (t==1)
        {
            cin>>u;
            price.push_back(u);
            s1.insert(price.size()-1);
            s2.insert(price.size()-1);
        }
        else if (t==2)
        {
            u=(*(s2.begin()));
            cout<<u<<endl;
            s1.erase(u);
            s2.erase(u);
        }
        else if (t==3)
        {
            u=(*(s1.begin()));
            cout<<u<<endl;
            s1.erase(u);
            s2.erase(u);
        }
    }
}
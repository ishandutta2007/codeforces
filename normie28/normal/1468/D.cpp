#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long dx[100001],dy[100001],n,m,i,j,k,t,t1,u,v,a,b,res=0,st,en;
vector<ll> items;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n;
        cin>>m>>a>>b;
        items.clear();
        for (i=1;i<=m;i++)
        {
            cin>>u;
            items.push_back(u);
        }
        sort(items.begin(),items.end());
        if (abs(a-b)==1) cout<<0<<endl;
        else
        {
            if (a<b)
            {
                st=(b-2);
                en=(b-2)-(b-a-2);
            }
            else
            {
                st=(n-b-1);
                en=(n-b-1)-(a-b-2);
            }
            res=0;
            for (i=m-1;i>=0;i--)
            {
                if ((st>=en)and(st>=items[i])) {res++; st--;}
            }
            cout<<res<<endl;
        }
    }
}
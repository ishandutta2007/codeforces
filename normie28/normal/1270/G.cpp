#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int used[1000001];
vector<int> lis;
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    cin>>n;
    lis.clear();
    for (i=1;i<=n;i++) {cin>>arr[i]; used[i]=-1;}
    u=1;
    for (i=0;;i++)
    {
        used[u]=i;
        lis.push_back(u);
        u-=arr[u];
        if (used[u]>=0)
        {
            cout<<lis.size()-used[u]<<"\n";
            for (j=used[u];j<lis.size();j++) cout<<lis[j]<<' ';
            cout<<"\n";
            break;
        }
    }
    }
}
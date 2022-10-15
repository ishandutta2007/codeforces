#include <bits/stdc++.h>
using namespace std;
map<int,vector<int>> lmao;
int n,m,i,j,k,t,t1,u,v,a,b,c,d;
vector<int> kek;
int arr[200001],brr[200001],crr[200001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (i=0;i<n;i++)
    {
        cin>>u;
        lmao[u].push_back(i);
        brr[i]=-1;
    }
    for (i=0;i<m;i++)
    {
        cin>>crr[i];
        kek.push_back(i);
    }
    sort(kek.begin(),kek.end(),[](int a, int b){return (crr[a]<crr[b]);});
    for (auto g : kek)
    {
        u=crr[g];
        a=0;
        while(true)
        {
            if (lmao[u].size()) break;
            else 
            {
                if (u==1) break;
                u=u-u/2;
                a++;
            }
        }
        if (lmao[u].size())
        {
            c++;
            d+=a;
            arr[g]=a;
            brr[lmao[u].back()]=g;
            lmao[u].pop_back();
        }
    }
    cout<<c<<' '<<d<<endl;
    for (i=0;i<m;i++) cout<<arr[i]<<' '; cout<<endl;
    for (i=0;i<n;i++) cout<<brr[i]+1<<' '; cout<<endl;
}
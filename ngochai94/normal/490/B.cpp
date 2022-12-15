#include <bits/stdc++.h>
using namespace std;

int n,a,b;
map<int,int> dic2,dic3;
int lis1[200002],lis2[200002];

int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a>>b;
        dic2[a]=b;
        lis1[i]=a;
        lis2[i]=b;
    }
    for (int i=0;i<n;i++)
    {
        dic3[lis1[i]]=0;
        dic3[lis2[i]]=0;
    }
    for (int i=0;i<n;i++) dic3[lis2[i]]=1;
    int cur1;
    for (int i=0;i<n;i++) if(dic3[lis1[i]]==0) cur1=lis1[i];
    int cur2=0;
    if (n%2==0) cur2=dic2[cur2];
    if (n%2==0) cout<<cur1<<' '<<cur2<<' ';
    else
    {
        cout<<cur1<<' ';
        int tmp=cur2;
        cur2=cur1;
        cur1=tmp;
    }
    for (int i=0;i<(n-1)/2;i++)
    {
        cur1=dic2[cur1];
        cur2=dic2[cur2];
        cout<<cur1<<' '<<cur2<<' ';
    }
    return 0;
}
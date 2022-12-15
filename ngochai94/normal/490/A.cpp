#include <bits/stdc++.h>
using namespace std;

int n,t,n1,n2,n3;
int t1[5000],t2[5000],t3[5000];

int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n;
    n1=0;
    n2=0;
    n3=0;
    for (int i=1;i<=n;i++)
    {
        cin>>t;
        if(t==1)
        {
            n1++;
            t1[n1]=i;
        }
        else if(t==2)
        {
            n2++;
            t2[n2]=i;
        }
        else
        {
            n3++;
            t3[n3]=i;
        }
    }
    int k;
    k=min(n1,min(n2,n3));
    cout<<k<<endl;
    for (int i=1;i<=k;i++) cout<<t1[i]<<' '<<t2[i]<<' '<<t3[i]<<endl;
    return 0;
}
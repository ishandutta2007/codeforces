#include <bits/stdc++.h>

using namespace std;
int ans1[500007];
int ans2[500007];
bool p[10000007];
int divisor[10000007];
int ile[10000007];
int sum[10000007];

int main()
{
    for(int i=2;i<=10000000;i++) sum[i]=1;
    for(int i=2;i<=5000000;i++)
    {
        if(!p[i])
        {
            for(int j=2*i;j<=10000000;j+=i)
            {
                p[j]=1;
                ile[j]++;
                if(divisor[j]==0) divisor[j]=i;
                sum[j]*=i;
            }
        }
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(ile[a]<2)
        {
            ans1[i]=-1;
            ans2[i]=-1;
        }
        else
        {
            ans1[i]=divisor[a];
            ans2[i]=sum[a]/divisor[a];
        }
    }
    for(int i=0;i<n;i++) cout<<ans1[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++) cout<<ans2[i]<<" ";
    cout<<endl;
    return 0;
}
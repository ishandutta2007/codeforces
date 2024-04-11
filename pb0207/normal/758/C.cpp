#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long a[105][105];

int main()
{
    long long n,m,k,x,y;
    cin>>n>>m>>k>>x>>y;
    long long lh=0;
    for(int i=0;i<n;i++)
        lh+=m;
    for(int i=n-2;i>0;i--)
        lh+=m;
    for(int i=1;i<n-1;i++)
        for(int j=0;j<m;j++)
        a[i][j]+=2*(k/lh);
    for(int i=0;i<m;i++)
        a[0][i]+=k/lh;
    if(n!=1)
    {
        for(int i=0;i<m;i++)
            a[n-1][i]+=k/lh;
    }
    k%=lh;
    if(k!=0)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                a[i][j]++;
                k--;
                if(k==0)
                    break;
            }
            if(k==0)
                break;
        }
        if(k!=0)
        {
            for(int i=n-2;i>0;i--){
                for(int j=0;j<m;j++)
                {
                    a[i][j]++;
                    k--;
                    if(k==0)
                        break;
                }
                if(k==0)
                    break;
            }
        }
    }
    long long max1=0,min1=1e18+1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            //cout<<a[i][j]<<endl;
            max1=max(a[i][j],max1);
            min1=min(a[i][j],min1);
        }
    cout<<max1<<' '<<min1<<' '<<a[x-1][y-1]<<endl;
    return 0;
}
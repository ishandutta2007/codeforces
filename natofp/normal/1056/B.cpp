#include <iostream>
#include <bits/stdc++.h>

using namespace std;


long long int ile(int a,int b,int ile,int mod)
{
    long long int ans=0;
    int w=(b-a+1)/mod;
    ans+=w;
    b-=w*mod;
    if(ile>=a && ile<=b) ans++;
    return ans;

}

int main()
{
    int n,m;
    cin>>n>>m;
    long long int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i*i+j*j)%m==0)
            {
                long long int a,b;
                a=ile(1,n,i,m);
                b=ile(1,n,j,m);
                ans+=a*b;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
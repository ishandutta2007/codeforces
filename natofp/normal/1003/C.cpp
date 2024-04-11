#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int * a;
    double maxx=0;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-k+1;i++)
    {
        double sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            if(j>=(i+k-1))
            {
                if((double)sum/(double)(j-i+1)>maxx) maxx=(double)sum/(double)(j-i+1);
            }
        }
    }
    cout<<setprecision(15)<<maxx;


    return 0;
}
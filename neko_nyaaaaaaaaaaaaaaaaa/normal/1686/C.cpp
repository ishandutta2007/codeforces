#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    // your code goes here
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        int b[n];
        if(n%2==1)
        {
            for(int i=0;i<n;i++)
            {
                b[(2*i)%n]=a[i];
            }
        }
        else
        {
            for(int i=0;i<n/2;i++)
            {
                b[(2*i)%n]=a[i];
            }
            for(int i=n/2;i<n;i++)
            {
                b[(2*i+1)%n]=a[i];
            }
        }
        bool bb=1;
        for(int i=0;i<n;i++)
        {
            if(!( (b[i]<b[(i-1+n)%n] && b[i]<b[(i+1)%n]) || (b[i]>b[(i-1+n)%n] && b[i]>b[(i+1)%n]) ))
            {
                bb=0;
                break;
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<b[i]<<" ";
        //     cout<<"\n";
        if(bb==0)
        {
            cout<<"NO\n";
            continue;
        }
        else
        {
            cout<<"YES\n";
            for(int i=0;i<n;i++)
            cout<<b[i]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l,n;
    cin>>n>>l;
    int * a;
    a=new int[n];
    for(int i=1;i<n;i++) cin>>a[i];
    int ans=0;
    int * ile;
    ile=new int[n];
    for(int i=0;i<n;i++) ile[i]=0;
    for(int i=1;i<=l;i++)
    {
        ile[i]=a[i];
    }
    int akt=1;
    int naj=l+1;
    while(akt<n)
    {
        if(naj<=akt) {naj++; continue;}
        int t=ile[akt];
        if(n-akt<=l)
        {
            ans+=ile[akt];
        }
        else
        {
            while(naj-akt<=l && t>0)
        {
            int k=a[naj]-ile[naj];
            if(t<=k)
            {
                ile[naj]+=t;
                t=0;


            }
            else
            {
                t-=k;
                ile[naj]+=k;
                naj++;
            }

        }

        }
        akt++;

    }
    cout<<ans;
    return 0;
}
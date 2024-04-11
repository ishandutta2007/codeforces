#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,k;
   cin>>n>>k;
   int * tab;
   tab=new int[n];
   for(int i=0;i<n;i++)
     cin>>tab[i];
    vector <int> a;
    for(int i=0;i<n;i++)
    {
        bool xd=true;
        for(int j=0;j<a.size();j++)
        {
            if(tab[i]==a[j]) xd=false;

        }
        if(xd) a.push_back(tab[i]);
    }
    if(a.size()<k) cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<k;i++)
        {
            int x=a[i];
            int z=0;
            while(tab[z]!=x)
                z++;
            cout<<z+1<<" ";
        }
    }

    return 0;
}
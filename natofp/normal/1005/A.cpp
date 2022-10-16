#include <iostream>
#include <bits/stdc++.h>2
using namespace std;

int main()
{
    int n;
    cin>>n;
    int k=0;
    vector <int> odp;

    int * a;
    a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {

            if(a[i]!=(a[i-1]+1))
        {
            k++; odp.push_back(a[i-1]);
        }


    }
    k++; odp.push_back(a[n-1]);
    cout<<k<<endl;
    for(int i=0;i<k;i++) cout<<odp[i]<<" ";

    return 0;
}
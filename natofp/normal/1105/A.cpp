#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cost=1e9;
int naj=-1;

int main()
{
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=100;i++)
    {
        int t=i;
        int suma=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]>t) suma+=max(0,a[j]-t-1);
            else if(a[j]<t) suma+=max(0,t-a[j]-1);
        }
        if(suma<cost) {cost=suma; naj=i;}
    }
    cout<<naj<<" "<<cost;
    return 0;
}
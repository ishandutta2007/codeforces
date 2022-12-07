#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int myarr[n];
    for(int i=0;i<n;i++)
    {
        cin>>myarr[i];
    }
    sort(myarr,myarr+n);
    if(k==0)
    {
        if(myarr[0]==1)
            cout<<"-1"<<endl;
        else
            cout<<"1"<<endl;
    }
    else if(k==n)
    {
        cout<<myarr[n-1]<<endl;
    }
    else
    {
        int answer = myarr[k-1];
        if(answer<myarr[k])
            cout<<answer<<endl;
        else
            cout<<"-1"<<endl;
    }
}
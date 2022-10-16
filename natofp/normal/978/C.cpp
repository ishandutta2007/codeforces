#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <long long int>::iterator it;
    int n,m;
    cin>>n>>m;
    vector <long long int> a(n);
    vector <long long int> b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    vector <long long int> prefix(n+1);
    prefix[0]=0;
    for(int i=1;i<=n;i++)
        prefix[i]=prefix[i-1]+a[i-1];
    for(int j=0;j<m;j++)
    {

        it=lower_bound(prefix.begin(),prefix.end(),b[j]);
        int i=it-prefix.begin();
        cout<<i<<" "<<b[j]-prefix[i-1]<<endl;
    }



    return 0;
}
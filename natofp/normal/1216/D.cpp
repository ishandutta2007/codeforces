#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int naj=a[n-1];
    int ile=naj-a[0];
    for(int i=1;i<n;i++)
    {
        int akt=a[i];
        if(akt==naj) continue;
        ile=__gcd(ile,naj-akt);
    }
    ll ludzie=0;
    for(int i=0;i<n;i++)
    {
        ludzie+=(naj-a[i])/ile;
    }
    cout<<ludzie<<" "<<ile<<endl;
    return 0;
}
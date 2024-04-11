#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int q; cin>>q;
    while(q--)
    {
        long long int k,n,a,b;
        cin>>k>>n>>a>>b;
        if(b*n>=k)
        {
            cout<<-1<<"\n";
            continue;
        }
        long long int left=k-b*n;
        left--;
        long long int roz=a-b;
        cout<<min(left/roz,n)<<"\n";
    }
    return 0;
}
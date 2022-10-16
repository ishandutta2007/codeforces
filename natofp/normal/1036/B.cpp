#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q; cin>>q;
    long long int n,m,k;
     long long int w=0;
    for(int i=0;i<q;i++)
    {
        cin>>n>>m>>k;

        if(max(n,m)>k) {cout<<"-1"<<endl; continue;}


            if(m%2==n%2 && k%2!=n%2) w=k-2;
            else if(m%2==n%2 && k%2==n%2) w=k;
            else w=k-1;


        cout<<w<<endl;

    }

    return 0;
}
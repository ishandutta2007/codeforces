#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q; cin>>q;
    while(q--)
    {
        int l1,r1,l2,r2; cin>>l1>>r1>>l2>>r2;
        if(l1==r1 || l2==r2)
        {
            cout<<l1<<" "<<r1<<endl;
        }
        else if(l1==r1)
        {
            cout<<l1<<" ";
            if(l1!=l2) cout<<l2<<endl;
            else cout<<l2+1<<endl;
        }
        else if(l2==r2)
        {
            if(l1!=l2) cout<<l1<<" "<<l2<<endl;
            else cout<<l1+1<<" "<<l2<<endl;
        }
        else
        {
            cout<<l1<<" ";
            if(l2!=l1) cout<<l2<<endl;
            else cout<<l2+1<<endl;
        }
    }
    return 0;
}
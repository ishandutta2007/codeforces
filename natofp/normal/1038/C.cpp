#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    int * a; int* b;
    a=new int[n];
    b=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    long long int x=0;
    long long int y=0;
    int c,d;
    c=n-1;
    d=n-1;
    for(int i=0;i<2*n;i++)
    {
        if(i%2==0)
        {
            if(c==-1)
            {
                d--;
            }
            else if(d==-1)
            {
                x+=a[c];
                c--;
            }
            else
            {
                if(a[c]>b[d]) {x+=a[c]; c--;}
                else {d--;}
            }
        }
        else
        {
            if(c==-1)
            {
                y+=b[d]; d--;
            }
            else if(d==-1)
            {

                c--;
            }
            else
            {
                if(b[d]>a[c]) {y+=b[d]; d--;}
                else {c--;}
            }
        }
    }
    cout<<x-y;



    return 0;
}
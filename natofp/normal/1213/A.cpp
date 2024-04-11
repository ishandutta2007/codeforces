#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

    int n; cin>>n;
    int a=0;
    int b=0;
    for(int i=0;i<n;i++)
    {
            int x; cin>>x;
            if(x%2) a++;
            else b++;
    }
    cout<<min(a,b);
    return 0;
}
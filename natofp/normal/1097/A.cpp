#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a; cin>>a;
    string x[5];
    for(int i=0;i<5;i++) cin>>x[i];
    for(int i=0;i<5;i++)
    {
        if(x[i][0]==a[0] || x[i][1]==a[1]) {cout<<"YES"; return 0;}
    }
    cout<<"NO";
    return 0;
}
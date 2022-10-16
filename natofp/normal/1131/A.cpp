#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
    ll w1,h1,w2,h2; cin>>w1>>h1>>w2>>h2;
    ll res=0;
    res+=(h1+h2+2)*2;
    res+=2*w1;
    cout<<res;
    return 0;
}
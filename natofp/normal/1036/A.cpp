#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,k;
    cin>>n>>k;
    long long w=k/n;
    if(k%n!=0) w++;
    cout<<w;

    return 0;
}
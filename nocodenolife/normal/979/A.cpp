#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int n;
    cin>>n;
    if(n==0)
    {
        cout<<"0";
        return 0;
    }
    long long int total = n+1;
    if(total%2==0)
    {
        cout<<total/2;
    }
    else
    {
        cout<<total;
    }
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    long myarr[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        long k;
        cin>>k;
        myarr[i] = myarr[i-1]+k;
    }
    long ans = (myarr[n]+1)/2;
    for(int i=1;i<=n;i++)
    {
        if(myarr[i]>=ans)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
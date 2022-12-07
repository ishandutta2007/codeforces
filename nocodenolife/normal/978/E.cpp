#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n,w;
    cin>>n>>w;
    int sum[n];
    cin>>sum[0];
    for(int i=1;i<n;i++)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    sort(sum, sum+n);
    int min,max;
    
    
    if(sum[0]<0)
    {
        min = -sum[0];
    }
    else
        min =0;
    
    
    if(sum[n-1]>w)
        max =-1;
    else if(sum[n-1]<0)
        max = w;
    else
        max = w-sum[n-1];
    
    int answer = max-min+1;
    
    if(answer<=0)
        cout<<"0";
    else
        cout<<answer;
    return 0;
}
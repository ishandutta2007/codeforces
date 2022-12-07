#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    int rev[n];
    int inuse[1001] = {0};
    int num = n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        rev[n-1-i] = arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(inuse[rev[i]]==0)
            inuse[rev[i]]=1;
        else
        {
            rev[i]=-1;
            num--;
        }
    }
    cout<<num<<endl;
    for(int i=0;i<n;i++)
    {
        if(rev[n-1-i]>=0)
            cout<<rev[n-1-i]<<" ";
    }
    
    
    return 0;
}
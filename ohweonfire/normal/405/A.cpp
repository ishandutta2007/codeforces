#include <iostream>
#include <algorithm>
using namespace std;
int num[101];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i];
    sort(num,num+n);
    for(int i=0;i<n;i++)cout<<num[i]<<" ";
    
    return 0;
}
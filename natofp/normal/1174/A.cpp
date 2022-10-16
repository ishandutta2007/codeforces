#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int * a=new int[2*n+1];
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+1+2*n);
    int sum1=0;
    int sum2=0;
    for(int i=1;i<=n;i++) sum1+=a[i];
    for(int i=n+1;i<=2*n;i++) sum2+=a[i];
    if(sum1==sum2)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=2*n;i++) cout<<a[i]<<" ";
    return 0;
}
#include <iostream>
long long n,m,i,j=1;using namespace std;
int main()
{
    cin>>n;
    for (i=1;i<=n;i++) j*=i;
    j/=n/2;
    j/=n/2;j/=2;
    cout<<j;
}
#include <iostream>

using namespace std;


int main()
{

    long long int n,m,a;
    cin>>n>>m>>a;
    long long int x,y;
    if(n%a==0) x=n/a;
    else x=n/a+1;
    if(m%a==0) y=m/a;
    else y=m/a+1;
    cout<<x*y;
    return 0;
}
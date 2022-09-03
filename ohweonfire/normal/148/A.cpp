#include <iostream>
using namespace std;
int a,b,c,d,n,z;
int main()
{
    cin>>a>>b>>c>>d>>n;
    for(int i=1;i<=n;i++)
        if(i%a&&i%b&&i%c&&i%d)z++;
    cout<<n-z;
    return 0;
}
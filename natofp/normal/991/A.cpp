#include <iostream>

using namespace std;

int main()
{
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    if(c>a || c>b || n<a || n<b || n<c) cout<<"-1";
    else
    {
        if(n-a-b+c>0) cout<<n-a-b+c;
        else cout<<"-1";
    }
    return 0;
}
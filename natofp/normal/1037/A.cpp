#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int i=0;
    while(n)
    {
        i++; n/=2;
    }
    cout<<i;
    return 0;
}
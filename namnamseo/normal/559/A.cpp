#include <iostream>

using namespace std;

int a[6];

int s(int a){ return a*a; }

int main()
{
    int i;
    for(i=0;i<6;++i) cin>>a[i];
    cout<<s(a[0]+a[1]+a[2])-s(a[0])-s(a[2])-s(a[4]);
    return 0;
}
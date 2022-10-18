#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    int licznik=0;
    for(int i=0;i<=31;i++)
    {
        if((1<<i & x) == 1<<i) licznik++;
    }

    cout<<licznik;
    return 0;
}
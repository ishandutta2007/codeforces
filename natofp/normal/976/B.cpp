#include <iostream>

using namespace std;

int main()
{
    long long int x,y;
    long long int n,m;
    long long int k;
    cin>>n>>m>>k;
    if(k<n) {x=k+1; y=1; cout<<x<<" "<<y; return 0;}
    else
    {
        k-=n;

        x=n-(k/(m-1));
        int licznik=k%(m-1);


        if(x%2==1)
        {
            y=m-licznik;

        }
        else y=2+licznik;



    }
    cout<<x<<" "<<y;
    return 0;
}
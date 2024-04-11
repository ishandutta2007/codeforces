#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string wyraz;
    cin>>wyraz;
    int licznik=0;
    for(int i=0;i<n;i++)
    {
        if(wyraz[i]=='1') licznik++;
    }
    if(licznik==0) cout<<"0";
    if(licznik>=1) {cout<<"1"; for(int i=0;i<n-licznik;i++){cout<<"0";}}



    return 0;
}
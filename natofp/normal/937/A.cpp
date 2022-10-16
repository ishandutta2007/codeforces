#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int tab[601];
    for(int i=0;i<601;i++)
    {
        tab[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        tab[x]++;
    }
    int suma=0;
    for(int i=1;i<601;i++)
    {
        if(tab[i]>0) suma++;
    }
    cout<<suma;
    return 0;
}
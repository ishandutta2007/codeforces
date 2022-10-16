#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int * tab;
    tab=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>tab[i];
    }
    for(int i=1;i<n;i++)
    {
        if(tab[tab[tab[i]]]==i) {cout<<"Yes"; delete [] tab; return 0;}
    }

    cout<<"No";
    delete [] tab;
    return 0;
}
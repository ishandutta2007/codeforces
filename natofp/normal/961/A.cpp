#include <iostream>

using namespace std;

int main()
{
    int n,m,x;
    cin>>n>>m;
    int * tab;
    tab=new int[n];
    for(int i=0;i<n;i++)
    {
        tab[i]=0;
    }
    for(int j=0;j<m;j++)
    {
        cin>>x;
        tab[x-1]++;
    }
    int naj=1111111;
    for(int i=0;i<n;i++)
    {
        if(tab[i]<naj) naj=tab[i];
    }
    cout<<naj;
    delete [] tab;
    return 0;
}
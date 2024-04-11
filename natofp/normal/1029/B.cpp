#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int * tab;
    tab=new int[n];
    for(int i=0;i<n;i++) cin>>tab[i];
    int akt=1;
    int naj=0;
    for(int i=1;i<n;i++)
    {
        if(tab[i]<=2*tab[i-1]) akt++;
        else
        {
            if(naj<akt) naj=akt;
            akt =1;
        }
    }
    if(naj<akt) naj=akt;
    cout<<naj;
    return 0;
}
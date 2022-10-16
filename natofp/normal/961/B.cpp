#include <iostream>

using namespace std;

int main()
{
    int k,n;
    cin>>n;
    cin>>k;
    int * theorems;
    theorems=new int[n];
    int * time;
    time=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>theorems[i];
    }
     for(int i=0;i<n;i++)
    {
        cin>>time[i];
    }
    int suma=0;
    int licznik=0;
    int naj;
    for(int i=0;i<k;i++)
    {
        if(time[i]==0) suma+=theorems[i];
    }
    naj=suma;
    for(int i=k;i<n;i++)
    {
        if(time[i-k]==0) suma-=theorems[i-k];
        if(time[i]==0) suma+=theorems[i];
        if(suma>naj) {naj=suma; licznik=i-k+1;}

    }
    for(int i=licznik;i<licznik+k;i++)
    {
        time[i]=1;
    }
    long long int wynik=0;
    for(int i=0;i<n;i++)
    {
        if(time[i]==1) wynik+=theorems[i];
    }

    cout<<wynik;

    delete [] time;
    delete [] theorems;
    return 0;
}
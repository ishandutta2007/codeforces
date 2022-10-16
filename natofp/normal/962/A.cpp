#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int * tab;
    tab=new int[n];
    int suma=0;
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
        suma+=tab[i];
    }
    int wynik=0;
    for(int i=0;i<n;i++)
    {
        wynik+=tab[i];
        if (wynik*2>=suma) {cout<<i+1; return 0;}
    }

}
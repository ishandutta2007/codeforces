#include <iostream>
using namespace std;

int main()
{
    string maslo;
    cin >> maslo;
    long long hejwi = 0;
    long long wynik = 0;
    char wyczekuj1 = 'h';
    char wyczekuj2 = 'm';
    for (int i=0; i<maslo.size(); i++)
    {
        if (maslo[i]!=wyczekuj1)
        {
                                wyczekuj1='h';
        }
        if (maslo[i]=='h')
        {
                          wyczekuj1 = 'e';
        }
        if (maslo[i]=='e' && wyczekuj1=='e')
        {
                          wyczekuj1 = 'a';
        }
        if (maslo[i]=='a' && wyczekuj1=='a')
        {
                          wyczekuj1 = 'v';
        }
        if (maslo[i]=='v' && wyczekuj1=='v')
        {
                          wyczekuj1 = 'y';
        }
        if (maslo[i]=='y' && wyczekuj1=='y')
        {
                          wyczekuj1 = 'h';
                          hejwi++;
        }
        if (maslo[i]!=wyczekuj2)
        {
                                wyczekuj2='h';
        }
        if (maslo[i]=='m')
        {
                          wyczekuj2 = 'e';
        }
        if (maslo[i]=='e' && wyczekuj2=='e')
        {
                          wyczekuj2 = 't';
        }
        if (maslo[i]=='t' && wyczekuj2=='t')
        {
                          wyczekuj2 = 'a';
        }
        if (maslo[i]=='a' && wyczekuj2=='a')
        {
                          wyczekuj2 = 'l';
        }
        if (maslo[i]=='l' && wyczekuj2=='l')
        {
                          wyczekuj2 = 'm';
                          wynik+=hejwi;
        }
    }
    cout << wynik;
    return 0;
}
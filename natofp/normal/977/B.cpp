#include <iostream>

using namespace std;

int main()
{
    int tab[26*26];
    int n;
    cin>>n;
    string wyraz;
    cin>>wyraz;
    for(int i=0;i<26*26;i++)
        tab[i]=0;
    for(int i=1;i<n;i++)
    {
        tab[(wyraz[i-1]-65)*26+wyraz[i]-65]++;
    }
    int x=0;
    int wynik=0;
     for(int i=0;i<26*26;i++)
     {
         if(tab[i]>wynik) {wynik=tab[i]; x=i;}
     }
        cout<<(char)(65+x/26)<<(char)(65+x%26);

    return 0;
}
#include <iostream>

using namespace std;


int main()
{
   int n,k;
   cin>>n>>k;
   string s;
   cin>>s;
   int tab[26];
   for(int i=0;i<26;i++)
      tab[i]=0;
   for(int i=0;i<s.length();i++)
      tab[s[i]-97]++;
    int j=0;
    int suma=tab[0];
    while(j<26 && suma<k)
    {
        j++;
        suma+=tab[j];
    }

    int w=k-(suma-tab[j]);
    string wynik="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]-97>j) wynik+=s[i];
        else if(s[i]-97==j) w--;
        if(s[i]-97==j && w<0) wynik+=s[i];
    }
    cout<<wynik;
    return 0;
}
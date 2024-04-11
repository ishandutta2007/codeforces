#include <iostream>
#include <bits/stdc++.h>
using namespace std;


string przedzial(string a,int start,int dlugosc)
{
    string wynik="";
    int i=0;
    while(i<dlugosc)
    {
        wynik+=a[start+i];
        i++;
    }
    return wynik;
}


bool compare(string a,string b)
{
    if(a.length()>=b.length()) return 0;
    return 1;
}
bool czy(string a,string b)
{
    for(int i=0;i<b.length()-a.length()+1;i++)
    {
        if(przedzial(b,i,a.length())==a) return 1;
    }
    return 0;
}

int main()
{
   int n;
   cin>>n;
  vector <string> tab(n);
   for(int i=0;i<n;i++)
      cin>>tab[i];
   sort(tab.begin(),tab.end(),compare);
   bool wynik=true;
   for(int i=0;i<n-1;i++)
   {
        if(!(czy(tab[i],tab[i+1]))) wynik=false;
   }
   if(wynik==0) cout<<"NO";
   else
   {
       cout<<"YES"<<endl;
       for(int i=0;i<n;i++)
        cout<<tab[i]<<endl;
   }

    return 0;
}
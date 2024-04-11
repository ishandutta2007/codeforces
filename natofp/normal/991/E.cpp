#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> litery(10,0);

long long int silnia(int n)
{
    long long int w=1;
    if(n==0) return 1;
    else for(int i=1;i<=n;i++) w*=i;
    return w;
}
long long policz(string a)
{
    vector<int> tab(10,0);
    for(int i=0;i<a.length();i++)
        tab[a[i]-48]++;
    for(int i=0;i<10;i++)
    if(litery[i]!=0 && tab[i]==0) return 0;
    long long wynik=0;
    wynik=silnia(a.length());
    for(int i=0;i<10;i++) wynik/=silnia(tab[i]);

    long long odejmij=0;
    if(tab[0]!=0)
    {
        tab[0]--;
    odejmij=silnia(a.length()-1);
    for(int i=0;i<10;i++) odejmij/=silnia(tab[i]);
    }
    return(wynik-odejmij);
}


int main()
{
    long long w=0;
    string n;
    cin>>n;
    for(int i=0;i<n.length();i++)
        litery[n[i]-48]++;
    set<string> a;
    int k=1<<n.length();

    for(int i=0;i<k;i++)
    {
        string wynik="";
        for(int j=0;j<n.length();j++)
        {

            if(i&(1<<j)) wynik+=n[j];

        }
        sort(wynik.begin(),wynik.end());
        if(a.count(wynik)==0) {a.insert(wynik); w+=policz(wynik);}

    }
    cout<<w;
    return 0;
}
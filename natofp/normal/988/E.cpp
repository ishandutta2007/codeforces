#include <iostream>
#include <bits/stdc++.h>
using namespace std;


long long int liczba(vector<int> s)
{
    long long wynik=0;
    for(int i=0;i<s.size();i++)
    {
        wynik+=s[i];
        if(i!=s.size()-1) wynik*=10;
    }
    return wynik;
}



int zliczzera(vector<int> a)
{
    int i=0;
    int wynik=0;
    while(a.size()>0 && a[i]==0)
    {
        wynik++;
        i++;

    }
    return wynik;
}
int ustaw(vector<int> s,int a,int b)
{
    int wynik=0;
    for(int i=a;i<s.size()-1;i++)
    {
        swap(s[i],s[i+1]);
        wynik++;
        if(i+1==b) b--;
    }
    for(int j=b;j<s.size()-2;j++)
    {
        swap(s[j],s[j+1]);
        wynik++;
    }



    int x=zliczzera(s);
    if((x>=s.size()-2 && x!=0) || (liczba(s)%25LL!=0 && liczba(s)!=0)) return 10000;
    else return(wynik+x);
}


int main()
{
    int wynik=10000;
    string wyraz;
    cin>>wyraz;
    vector <int> s;
    for(int i=0;i<wyraz.length();i++)
        s.push_back(wyraz[i]-48);
    for(int i=0;i<s.size();i++)
        for(int j=0;j<s.size();j++)
    {
        if(i!=j) wynik=min(wynik,ustaw(s,i,j));
    }
    if(wynik<100)
        cout<<wynik;
    else cout<<"-1";

    return 0;
}
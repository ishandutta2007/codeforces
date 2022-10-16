#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{


    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int tab[26];
    for(int i=0;i<26;i++)
    {
        tab[i]=0;
    }
    for(int i=0;i<s.length();i++)
    {
        tab[s[i]-97]++;
    }
    int licznik=0;
    for(int i=0;i<26;i++)
    {
        if(tab[i]>0) licznik++;
    }
    char * tablica;
    tablica=new char[licznik];
    int zmienna=0;
    for(int i=0;i<26;i++)
    {
     if(tab[i]>0) {tablica[zmienna]=i+97; zmienna++;}
    }
    sort(tablica,tablica+licznik);

    string wynik="";
    if(k>n)
    {
        wynik+=s;
        for(int i=s.length();i<k;i++)
        {
            wynik+=tablica[0];
        }
    }
    if(k==n)
    {
        int szukana;
        int dostaw;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]!=tablica[licznik-1])
            {
                szukana=i;
                for(int j=0;j<licznik;j++)
                {
                    if(s[i]==tablica[j]) {dostaw=j+1;}
                }
                break;
            }
        }
        for(int i=0;i<szukana;i++)
        {
            wynik+=s[i];
        }
        wynik+=tablica[dostaw];
        for(int i=szukana+1;i<k;i++)
        {
            wynik+=tablica[0];
        }
    }
    else if(k<n)
    {
        int szukana;
        int dostaw;
        for(int i=k-1;i>=0;i--)
        {
            if(s[i]!=tablica[licznik-1])
            {
                szukana=i;
                for(int j=0;j<licznik;j++)
                {
                    if(s[i]==tablica[j]) {dostaw=j+1;}
                }
                break;
            }
        }
        for(int i=0;i<szukana;i++)
        {
            wynik+=s[i];
        }
        wynik+=tablica[dostaw];
        for(int i=szukana+1;i<k;i++)
        {
            wynik+=tablica[0];
        }

    }
    cout<<wynik;
    return 0;
}
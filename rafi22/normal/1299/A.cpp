#include <bits/stdc++.h>

using namespace std;

string Tobin(long long n)
{
    string wyn="",wyn1="";
    while(n>0)
    {
        wyn+=(char)(n%2+48);
        n/=2;
    }
    while(wyn.length()<32)wyn+='0';
    return wyn;
}

int ile[33];
vector <int> liczby[33];
bool used[200007];

int main()
{
    int n;
    cin>>n;
    int tab[n];
    int st=0;
    int mx=-1;

    for(int i=0;i<n;i++) cin>>tab[i];
    for(int j=0;j<n;j++)
    {
        string str=Tobin(tab[j]);
        for(int i=0;i<32;i++)
        {
            if(str[i]=='1')
            {
                liczby[i].push_back(j);
                ile[i]++;
            }
        }
    }
    for(int i=31;i>=0;i--)
    {
        if(ile[i]==1)
        {
            for(int j=0;j<liczby[i].size();j++)
            {
                if(!used[liczby[i][j]])
                cout<<tab[liczby[i][j]]<<" ";
                used[liczby[i][j]]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!used[i]) cout<<tab[i]<<" ";
    }
    return 0;
}
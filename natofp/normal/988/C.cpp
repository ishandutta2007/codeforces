#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int c,d,e,f;
    c=d=0;
    int k;
    cin>>k;
    vector <int> a[k+1];
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        for(int j=0;j<x;j++)

        {
            int h;
            cin>>h;
            a[i].push_back(h);
        }
    }
    map <long long int,int> mapa;
    for(int i=1;i<=k;i++)
    {
        long long int suma=0;
        for(int j=0;j<a[i].size();j++)
        {
            suma+=a[i][j];
        }
        for(int j=0;j<a[i].size();j++)
        {
            if(mapa[suma-a[i][j]]==0) mapa[suma-a[i][j]]=i;
            else
            {
                if(mapa[suma-a[i][j]]!=i)
                {
                    {c=i; d=mapa[suma-a[i][j]]; e=j+1;}
                }

            }
        }
    }
    if(c!=0)
    {
        int suma=0;
    int suma2=0;
    for(int i=0;i<a[c].size();i++)
    {
        suma2+=a[c][i];
    }
    suma2-=a[c][e-1];
    for(int i=0;i<a[d].size();i++)
    {
        suma+=a[d][i];
    }
    for(int i=0;i<a[d].size();i++)
    {
        if(suma-a[d][i]==suma2) f=i+1;
    }


        cout<<"YES"<<endl;
        cout<<c<<" "<<e<<endl;
        cout<<d<<" "<<f<<endl;
    }
    else cout<<"NO";


    return 0;
}
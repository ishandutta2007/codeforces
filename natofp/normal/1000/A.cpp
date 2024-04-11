#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int numer(string a)
{
    if(a=="M") return 0;
    if(a=="S") return 1;
    if(a=="L") return 2;
    if(a=="XS") return 3;
    if(a=="XL") return 4;
    if(a=="XXS") return 5;
    if(a=="XXL") return 6;
    if(a=="XXXS") return 7;
    if(a=="XXXL") return 8;

}

int main()
{
    int n;
    cin>>n;
    vector<string> a;
    vector<string> b;
    int w=0;
    string x;
    for(int i=0;i<n;i++)  {cin>>x; a.push_back(x);}
    for(int i=0;i<n;i++)    {cin>>x; b.push_back(x);}
    int tab[9];
    for(int i=0;i<9;i++) tab[i]=0;
    for(int i=0;i<n;i++)
    {
        tab[numer(a[i])]++;
    }
    for(int i=0;i<n;i++)
    {
        tab[numer(b[i])]--;
    }
    for(int i=0;i<9;i++) w+=abs(tab[i]);
    cout<<w/2;



    return 0;
}
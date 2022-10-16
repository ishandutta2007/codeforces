#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string braket;
const int nax=2e5+5;
vector<int> wynik(nax,-1);
vector<int> koniec(nax,0);
vector<int> balans[nax];

void zrob(int pocz,int kon,int kolor)
{
    if(kon<pocz) return;
    int daleko=koniec[pocz];
    if(daleko==kon)
    {
        wynik[pocz]=wynik[kon]=kolor%2;
        kolor++;
        zrob(pocz+1,kon-1,kolor);
        return;
    }
    else
    {
        zrob(pocz,daleko,kolor);
        zrob(daleko+1,kon,kolor);
        return;
    }
}

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    braket="1"+s;
    int bal=0;
    for(int i=1;i<=n;i++)
    {
        if(braket[i]=='(')
        {
            bal++;
            balans[bal].push_back(i);
        }
        else
        {
            int roz=balans[bal].size();
            roz--;
            int pozycja=balans[bal][roz];
            balans[bal].pop_back();
            koniec[pozycja]=i;
            bal--;
        }

    }
    zrob(1,n,0);
    for(int i=1;i<=n;i++) cout<<wynik[i];
    return 0;
}
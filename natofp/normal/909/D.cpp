#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e6+5;

int lewo[nax];
int prawo[nax];
int n;

vector<int> pos;
string s="1";
vector<int> nowe;
vector<int> zostaje;

void jd()
{
    zostaje.clear();
    nowe.clear();
    for(int i=0;i<pos.size();i++)
    {
        if(nowe.size() && nowe.back()==pos[i]) nowe.pop_back();
        int akt=pos[i];
        int lewy=lewo[akt];
        int prawy=prawo[akt];
        prawo[lewy]=prawy;
        lewo[prawy]=lewy;
        if(lewo[prawy]!=0 && prawo[lewy]!=n+1)
        {
            if(s[lewy]!=s[prawy])
            {
                if(nowe.size() && nowe.back()==lewy) nowe.pop_back();
                nowe.push_back(lewy);
                nowe.push_back(prawy);
            }
            else nowe.push_back(prawy);
        }
    }
    for(int i=0;i<nowe.size();i++)
    {
        int akt=nowe[i];
        bool ok = false;
        if(lewo[akt]!=0)
        {
            if(s[lewo[akt]]!=s[akt]) ok = true;
        }
        if(prawo[akt]!=n+1)
        {
            if(s[prawo[akt]]!=s[akt]) ok = true;
        }
        if(ok) zostaje.push_back(akt);
    }
    pos = zostaje;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string r; cin>>r;
    s+=r;
    n=s.length()-1;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            prawo[i]=i+1;
            lewo[i]=0;
            if(s[2]!=s[1]) pos.push_back(i);
        }
        else if(i==n)
        {
            lewo[i]=i-1;
            prawo[i]=n+1;
            if(s[n]!=s[n-1]) pos.push_back(i);
        }
        else
        {
            prawo[i]=i+1;
            if(s[i]!=s[i+1] || s[i]!=s[i-1]) pos.push_back(i);
            lewo[i]=i-1;
        }
    }
    int ile=0;
    while(pos.size())
    {
        ile++;
        jd();
    }
    cout<<ile<<endl;
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    vector<int> ziomki;
    vector<int> paski;
    while(q--)
    {
        ziomki.clear();
        paski.clear();
        int a,b; cin>>a>>b;
        string s; cin>>s;
        int n=s.length();
        int akt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='X')
            {
                if(akt>0) ziomki.push_back(akt);
                akt=0;
            }
            else
            {
                akt++;
            }
        }
        if(akt>0) ziomki.push_back(akt);
        bool czy = true;
        for(int i=0;i<ziomki.size();i++)
        {
            int akt=ziomki[i];
            if(akt>=b && akt<a)
            {
                czy = false;
            }
            if(akt>=a) paski.push_back(akt);
        }
        if(czy==false)
        {
            cout<<"NO"<<"\n"; continue;
        }
        sort(paski.begin(),paski.end());
        if(paski.size()==0)
        {
            cout<<"NO"<<"\n"; continue;
        }
        int ile=0;
        for(int i=0;i<paski.size();i++)
        {
            if(paski[i]>=2*b) ile++;
        }
        if(ile>=2)
        {
            cout<<"NO"<<"\n"; continue;
        }
        if(ile==0)
        {
            int roz=paski.size();
            if(roz%2==0)
            {
                cout<<"NO"<<"\n"; continue;
            }
            else
            {
                cout<<"YES"<<"\n"; continue;
            }
        }
        if(ile==1)
        {
            int rozmiar=0;
            bool ok =true;
            for(int i=0;i<paski.size();i++) rozmiar=max(rozmiar,paski[i]);
            int pozostale=paski.size()-1;
            for(int i=1;i<=rozmiar;i++)
            {
                int pocz=i;
                int kon=i+a-1;
                if(kon>rozmiar) break;
                int roz1=i-1;
                int roz2=rozmiar-a-roz1;
                int bonus=0;
                if(roz1>=2*b || roz2>=2*b) continue;
                if(roz1<a && roz1>=b) continue;
                if(roz2<a && roz2>=b) continue;
                if(roz1>=a) bonus++;
                if(roz2>=a) bonus++;
                if((pozostale+bonus)%2==0)
                {
                    ok = false;
                }
            }
            if(!ok)
            {
                cout<<"YES"<<"\n"; continue;
            }
            else
            {
                cout<<"NO"<<"\n"; continue;
            }
        }
    }
    return 0;
}
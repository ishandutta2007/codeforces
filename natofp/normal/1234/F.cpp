#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int roz=(1<<20);

int dp[roz];
int ile[roz];
int liczba[roz];

int bity(int k)
{
    int res=0;
    while(k)
    {
        if(k%2==1) res++;
        k/=2;
    }
    return res;
}

bool por(int a,int b)
{
    if(liczba[a]==liczba[b]) return a<b;
    return liczba[a]<liczba[b];
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s;
    set<char> a;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int j=i;
        a.clear();
        int kod=0;
        while(j<n)
        {
            if(a.count(s[j])==1) break;
            else
            {
                a.insert((s[j]));
                int val=s[j]-'a';
                kod=(kod|(1<<val));
                dp[kod]++;
            }
            j++;
        }
    }
    for(int i=0;i<roz;i++) liczba[i]=bity(i);
    vector<int> dpki;
    for(int i=0;i<roz;i++) dpki.push_back(i);
    sort(dpki.begin(),dpki.end(),por);
    for(int i=0;i<dpki.size();i++)
    {
        int akt=dpki[i];
        if(dp[akt]) ile[akt]=liczba[akt];
        for(int j=0;j<20;j++)
        {
            if((akt&(1<<j)))
            {
                ile[akt]=max(ile[akt],ile[akt^(1<<j)]);
            }
        }
    }
    int res=0;
    for(int i=0;i<(1<<20);i++)
    {
        int dope=((roz-1)^i);
        res=max(res,ile[i]+ile[dope]);
    }
    cout<<res;
    return 0;
}
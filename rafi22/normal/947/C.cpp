#include <bits/stdc++.h>

using namespace std;

int wiado[300007];
int klucz[300007];
int trie[15000000][3];
int power[37],pot=1,itr=0;



string Tobin(int n)
{
    string wyn="",wyn1="";
    while(n>0)
    {
        wyn+=(char)(n%2+48);
        n/=2;
    }
    while(wyn.length()<pot)wyn+='0';
    return wyn;
}


void trieInsert(string str)
{
    int p=0;
    for(int j=pot-1; j>=0; j--)
    {
        trie[p][2]++;
        if(trie[p][str[j]-48]==0)
        {
            trie[p][str[j]-48]=++itr;
            p=trie[p][str[j]-48];
        }
        else
            p=trie[p][str[j]-48];
    }
    trie[p][2]++;
}

int trieQuerry(string str)
{
    int Xor=0;
    int p=0,p1=0;
    for(int j=pot-1;j>=0;j--)
    {
        if(trie[p][str[j]-48]==0||trie[trie[p][str[j]-48]][2]==0)
        {
            Xor+=power[j];
            p1=trie[p][!(str[j]-48)];
            trie[p1][2]--;
            p=p1;
        }
        else
        {
            p1=trie[p][str[j]-48];
            trie[p1][2]--;
            p=p1;
        }

    }
    return Xor;
}
int main()
{
    power[0]=1;
    for(int i=1;i<=31;i++) power[i]=power[i-1]*2;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,mx=0,act=1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>wiado[i];
        mx=max(mx,wiado[i]);
    }
    for(int i=0;i<n;i++)
    {
        cin>>klucz[i];
        mx=max(mx,klucz[i]);
    }
    while(act<mx)
    {
        pot++;
        act*=2;
    }
    for(int i=0;i<n;i++)
    {
        trieInsert(Tobin(klucz[i]));
    }
    for(int i=0;i<n;i++)
    {
        cout<<trieQuerry(Tobin(wiado[i]))<<" ";
    }

    return 0;
}
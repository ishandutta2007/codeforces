#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> tab;

vector<long long int> sumy;
vector<int> wynik(55,0);
vector<int> wynik2(55,0);
vector<int> serio(55,0);

void policz(int par)
{
    if(par==2)
    {
        vector<int> s;
        s=wynik;
        wynik=wynik2;
        wynik2=s;
    }
    for(int i=54;i>=0;i--)
    {
        serio[i]=wynik[i]-wynik2[i];
    }
    for(int i=0;i<=54;i++)
    {
        if(serio[i]<0)
        {
            serio[i+1]--;
            serio[i]+=10;
        }
    }
}

void dodaj2(long long int x)
{
    for(int i=0;i<55;i++)
    {
        int t=x%10;
        wynik2[i]+=t;
        x/=10;
    }
    for(int i=0;i<55;i++)
    {
        if(wynik2[i]>=10)
        {
            int t=wynik2[i]/10;
            wynik2[i]%=10;
            wynik2[i+1]+=t;
        }
    }
}

void dodaj(long long int x)
{
    if(x<0)
    {
        x*=-1;
        dodaj2(x);
       return;
    }
    for(int i=0;i<55;i++)
    {
        int t=x%10;
        wynik[i]+=t;
        x/=10;
    }
    for(int i=0;i<55;i++)
    {
        if(wynik[i]>=10)
        {
            int t=wynik[i]/10;
            wynik[i]%=10;
            wynik[i+1]+=t;
        }
    }
}

long long int ile(int l,int r)
{
    if(l==0) return sumy[r];
    return sumy[r]-sumy[l-1];
}

int czy()
{
    for(int i=54;i>=0;i--)
    {
        if(wynik[i]>wynik2[i]) return 1;
        if(wynik2[i]>wynik[i]) return 2;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long int res=0;
    for(int i=0;i<n;i++)
    {
        tab[a[i]]++;
    }
    sumy.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        long long int akt=a[i];
        akt+=sumy[i-1];
        sumy.push_back(akt);
    }
    for(int i=0;i<n-1;i++)
    {
        int t=a[i];
        tab[t]--;
        long long int akt=0;
        long long int suma=ile(i+1,n-1);
        akt+=suma-1LL*(n-1-i)*t;
        akt+=tab[t-1];
        akt-=tab[t+1];
        dodaj(akt);
    }
    int idx;
    for(int i=54;i>=0;i--)
    {
        if(wynik[i]==0) continue;
        idx=i;
        break;
    }
    int ans=czy();
    if(ans==0) {cout<<0; return 0;}
    if(ans==1)
    {
        policz(1);
    }
    else policz(2);
    if(ans==2) cout<<"-";
    for(int i=54;i>=0;i--)
    {
        if(serio[i]!=0) {idx=i; break;}
    }
    for(int i=idx;i>=0;i--) cout<<serio[i];
    return 0;
}
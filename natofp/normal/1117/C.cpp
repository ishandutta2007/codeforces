#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll x1,y1;
ll x2,y2;
long long int n;
vector<char> a;
long long int dol=0;
long long int gora=0;
long long int prawo=0;
long long int lewo=0;


void zrob()
{
    for(int i=0;i<n;i++)
    {
        if(a[i]=='L') lewo++;
        if(a[i]=='R') prawo++;
        if(a[i]=='U') gora++;
        if(a[i]=='D') dol++;
    }
}

bool czy(long long int k)
{
    long long cykle=k/n;
    long long int reszta=k%n;
    long long int pion;
    long long int poziom;
    pion=gora-dol;
    poziom=prawo-lewo;
    long long int ileprawo=0,ilegora=0;
    ileprawo=cykle*poziom;
    ilegora=pion*cykle;
    for(int i=0;i<reszta;i++)
    {
        if(a[i]=='L') ileprawo--;
        if(a[i]=='R') ileprawo++;
        if(a[i]=='U') ilegora++;
        if(a[i]=='D') ilegora--;
    }
    long long potrzeba=0;
    potrzeba=abs(x2-(x1+ileprawo));
    potrzeba+=abs(y2-(y1+ilegora));
    if(potrzeba<=k) return true;
    return false;


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char x; cin>>x;
        a.push_back(x);
    }
    zrob();
    long long int lo=0;
    long long int hi=1e18+1;
    if(czy(hi)==false) {cout<<-1; return 0;}
    while(lo+1<hi)
    {
        long long int mid=(lo+hi)/2;
        if(czy(mid)==true) hi=mid;
        else lo=mid;
    }
    while(czy(lo)==false) lo++;
    cout<<lo<<endl;
    return 0;
}
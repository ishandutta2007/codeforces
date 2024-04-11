#include <iostream>
#include  <bits/stdc++.h>

using namespace std;


vector<long long int> HashValue(1000005,0);
long long int m=1000000009;
long long int p=31;
vector<long long int> potega(1000005,0);
bool czy(int a,int b,int c,int d,int n)
{
    if(d>n || b>n) return false;
    if((b-a)!=(d-c)) return false;
    if(a>c)
    {
        swap(a,c);
        swap(b,d);
    }
    long long int w1=HashValue[b]-HashValue[a-1];
    long long int w2=HashValue[d]-HashValue[c-1];
    if(w1<0) w1+=m;
    if(w2<0) w2+=m;
    if((w1*potega[c-a])%m==w2) return true;
    return false;

}



int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    string t,s;
    cin>>t; cin>>s;
    long long int n=s.length();
    HashValue[0]=0;
    long long int akt_pow=1;
    for(int i=1;i<=n;i++)
    {
        HashValue[i]=(HashValue[i-1]+(s[i-1]-'a'+1)*akt_pow)%m;
        akt_pow*=p;
        akt_pow%=m;
    }
    potega[0]=1;
    for(int i=1;i<=n;i++)
    {
        potega[i]=(potega[i-1]*p)%m;
    }
    int ile0=0;
    int ile1=0;
    for(int i=0;i<t.length();i++)
    {
        if(t[i]=='0') ile0++;
        else ile1++;
    }
    long long int ans=0;
    for(int i=1;i<=n;i++)
    {
        long long int dlugosc0=i;
        long long int dlugosc1;
        long long int xdd=ile0*dlugosc0;
        if((xdd>n) || (n-xdd)%ile1!=0) continue;
        else dlugosc1=(n-xdd)/ile1;
        if(dlugosc1<=0) continue;
        int suma=0;
        int wzor0a=-1;
        int wzor0b=-1;
        int wzor1a=-1;
        int wzor1b=-1;
        bool xd=true;
        for(int j=0;j<t.length();j++)
        {
            if(t[j]=='0')
            {
                if(wzor0a==-1)
                {
                    wzor0a=suma;
                    wzor0b=suma+dlugosc0-1;
                }
                else
                {

                    if(czy(wzor0a+1,wzor0b+1,suma+1,suma+dlugosc0,n)==false) {xd=false;}
                }
                suma+=dlugosc0;
            }
            else
            {
                if(wzor1a==-1)
                {
                    wzor1a=suma;
                    wzor1b=suma+dlugosc1-1;
                }
                else
                {
                    if(czy(wzor1a+1,wzor1b+1,suma+1,suma+dlugosc1,n)==false) { xd=false;}
                }
                suma+=dlugosc1;
            }
            if(xd==false)  break;
        }
        if(xd==true) ans++;
    }
    int k=t.length();
    if(n%k==0)
    {
        int y=n/k;
        if(czy(1,y,n-y+1,n,n)==true) ans--;
    }
    cout<<ans;



    return 0;
}
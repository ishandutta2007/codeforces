#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int ile(int n,int k)
{
    int wynik=0;
    wynik=(1<<k);
    wynik+=(~n);

    return wynik;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int ans=0;
    int n,k; cin>>n>>k;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1 && a[0]==0) {cout<<1<<endl; return 0;}
    map<int,int> s;
    int pop=0;
    s[a[0]]++;
    pop=a[0];
    if(a[0]!=0) ans++;
    for(int i=1;i<n;i++)
    {
        int x,y;
        int t=ile(a[i],k);
        t^=pop;
        a[i]^=pop;
        x=s[a[i]];
        y=s[t];
        if(a[i]==0) x++;
        if(t==0) y++;
        if(x>y)
        {
            s[t]++;
            ans+=i+1-y;
            pop=t;
        }
        else
        {
            s[a[i]]++;
            ans+=i+1-x;
            pop=a[i];
        }
    }

    cout<<ans;
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

long long getsum(int * tab,int n)
{

    long long int w=0;
    for(int i=0;i<n;i++) w+=tab[i];
    return w;
}

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;
    int * b;
    b=new int[m];
    for(int i=0;i<m;i++) cin>>b[i];
    if(getsum(a,n)!=getsum(b,m)) {cout<<"-1"; return 0;}
    int i=0;
    int j=0;
    long long akt1,akt2;
    akt1=0; akt2=0;
    int ans=0;
    while(i<n && j<m)
    {
        if(akt1==0) {akt1+=a[i]; i++;}
        else if(akt2==0) {akt2+=b[j]; j++;}
        else
        {
            if(akt1==akt2) {ans++; akt1=0; akt2=0;}
            else if(akt1>akt2) {akt2+=b[j]; j++;}
            else {akt1+=a[i]; i++;}
        }
    }
    cout<<++ans;

    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    int * b=new int[n+1];
    int * g=new int[m+1];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=m;i++) cin>>g[i];
    sort(b+1,b+1+n);
    int CHLOPIEC=b[1];
    for(int i=2;i<=n;i++) CHLOPIEC=max(CHLOPIEC,b[i]);
    int DZIEWCZYNKA=g[1];
    for(int i=2;i<=m;i++) DZIEWCZYNKA=min(DZIEWCZYNKA,g[i]);
    if(DZIEWCZYNKA<CHLOPIEC) {cout<<-1; return 0;}
    long long int sum=0;
    for(int i=1;i<=n;i++) sum+=b[i];
    sum*=(long long int)m;
    for(int i=1;i<=m;i++) sum+=g[i]-CHLOPIEC;
    if(CHLOPIEC!=DZIEWCZYNKA) sum+=(long long int)b[n]-b[n-1];
    cout<<sum;
    return 0;
}
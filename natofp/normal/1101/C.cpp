#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct seg
{
    int l,r;
    int nr;
};

bool por(seg a,seg b)
{
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
 int t; cin>>t;
 while(t--)
 {
     bool ok=false; int ile=-1;
     int n; cin>>n;
     vector<seg> a;
     for(int i=0;i<n;i++)
     {
         int x,y; cin>>x>>y;
         seg nowy;
         nowy.l=x; nowy.r=y;
         nowy.nr=i;
         a.push_back(nowy);
     }
     sort(a.begin(),a.end(),por);
     vector<int> ans(n,0);
     int naj=a[0].r;
     for(int i=1;i<n;i++)
     {
         if(a[i].l>naj) {ile=i; ok=true; break;}
         else naj=max(naj,a[i].r);
     }
     if(ok==false) {cout<<-1<<endl; continue;}
     for(int i=0;i<ile;i++) ans[a[i].nr]=1;
     for(int i=0;i<n;i++)
     {
         if(ans[i]==1) cout<<1<<" ";
         else cout<<2<<" ";
     }
     cout<<endl;
 }
    return 0;
}
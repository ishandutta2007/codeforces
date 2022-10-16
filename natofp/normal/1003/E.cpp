#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int nr;
    int indegree;
    int edge;
    int dis;
};

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
     int n,d,k;
     cin>>n>>d>>k;
     
     if(d>=n) {cout<<"NO"; return 0;}
     if(k==1)
     {
        if(d==1 && n==2) cout<<"YES"<<endl<<"1"<<" "<<"2"<<endl;
        else cout<<"NO";
        return 0;
     }
     
     vector<node> odp;
     node * a;
     a=new node[d+1];
     for(int i=0;i<=d;i++)
     {
         a[i].nr=i+1;
         if(i!=d) a[i].edge=i+2;
         else a[i].edge=0;
         a[i].indegree=2;
         if(i==0 || i==d) a[i].indegree--;
         a[i].dis=max(i,d-i);
     }
     queue<node> kolejka;
     for(int i=0;i<=d;i++)
     {
         kolejka.push(a[i]);
     }
     int l=d+2;
     while(l<=n)
     {
         if(kolejka.empty()) {cout<<"NO"; return 0;}
         node t=kolejka.front();
         kolejka.pop();
         odp.push_back(t);
         while(l<=n && t.indegree<k && t.dis<d)
         {
             node x;
             x.nr=l;
             l++;
             x.dis=t.dis+1;
             x.indegree=1;
             x.edge=t.nr;
             t.indegree++;
             kolejka.push(x);
         }


     }
     while(kolejka.empty()==false)
     {
         node x;
         x=kolejka.front();
         kolejka.pop();
         odp.push_back(x);
     }
     cout<<"YES"<<endl;
     for(int i=0;i<n;i++)
     {
         if(odp[i].edge!=0) cout<<odp[i].nr<<" "<<odp[i].edge<<endl;
     }
    return 0;
}
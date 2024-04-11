// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
//#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
//#define mod 1000000007
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define MAX 105
int v[MAX][MAX];
vector<vector<int>>opr;
 
int fnc(int m,int n)
{
 int ans=0;
 if(m<=n)
 {
     for(int i=0;i<m;i++)
     {
        int mn=INT_MAX;
        for(int j=0;j<n;j++)    mn=min(v[i][j],mn);
        for(int j=0;j<n;j++) v[i][j]-=mn;
        if(mn>0) {vector<int>x={0,i,mn};opr.push_back(x);}
        ans+=mn;
     }
     //cout<<ans<<endl;
     for(int j=0;j<n;j++)
     { ans+=v[0][j];
       if(v[0][j]>0)
       {vector<int>x={1,j,v[0][j]};opr.push_back(x);}
         int pp=v[0][j];
         for(int i=0;i<m;i++)
         {
            v[i][j]-=pp;
         }
     }
 }
 else
 {
    for(int j=0;j<n;j++)
    {  int mn=INT_MAX;
       for(int i=0;i<m;i++)   mn=min(mn,v[i][j]);
       if(mn>0) {vector<int>x={1,j,mn};opr.push_back(x);}
       ans+=mn;
       for(int i=0;i<m;i++) v[i][j]-=mn; 
    }
     
    for(int i=0;i<m;i++)
    {   ans+=v[i][0];
        int pp=v[i][0];
        for(int j=0;j<n;j++)    v[i][j]-=pp;
        {vector<int>x={0,i,pp};opr.push_back(x);} 
    }
 }
 int fg=1;
   for(int i=0;i<m && fg;i++)
   {
      for(int j=0;j<n;j++) {if(v[i][j]!=0) {fg=0;break;}}  
   }
   if(fg) return ans;
   return -1;
}
 
int main()
{ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int m,n;
//string s;
cin>>m>>n;
//cin>>s;
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
cin>>v[i][j];
int t=fnc(m,n);
if(t==-1) cout<<"-1"<<endl;
else
{
    cout<<t<<endl;
    for(int i=0;i<opr.size();i++)
    {   string yy="";
        if(opr[i][0]==0)yy="row";
        else yy="col";
        while(opr[i][2]--)
        {
            cout<<yy<<" "<<opr[i][1]+1<<endl;
        }
    }
}
//fnc(m);
//cout<<endl;
return 0;
}
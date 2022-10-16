#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> s;

int XD=0;

bool czypref(string a,string b,int k)
{
    for(int i=0;i<k;i++)
    {
        if(a[i]!=b[i]) return false;
    }
    return true;
}

bool czysuf(string a, string b,int k)
{
    int ile=b.length()-a.length();
    for(int i=0;i<k;i++)
    {
        if(a[i]!=b[ile+i]) return false;
    }
    return true;
}
vector<char> zrob(string x)
{
    vector<char> a;
    set<string> xd;
    for(int i=0;i<s.size();i++)
    {
        int k=s[i].length();
        if(czypref(s[i],x,k) && czysuf(s[i],x,k))
        {
            if(xd.count(s[i])==0)
            {
                a.push_back('P');
            xd.insert(s[i]);
            }
            else a.push_back('S');
        }
        else if(czypref(s[i],x,k)) a.push_back('P');
        else if(czysuf(s[i],x,k)) a.push_back('S');
        else return a;
    }

    XD=1;
    return a;
}

int main()
{
 int n; cin>>n;

 for(int i=0;i<2*n-2;i++)
 {
     string x; cin>>x;
     s.push_back(x);
 }
 if(n==2) {cout<<"PS"; return 0;}
 string a1,a2,b1,b2;
 int ile0,ile1;
 ile0=0; ile1=0;
 for(int i=0;i<2*n-2;i++)
 {
     if(s[i].length()==1)
     {
         if(ile0==0)
         {
             a1=s[i]; ile0++;
         }
         else a2=s[i];
     }
     if(s[i].length()==n-1)
     {
         if(ile1==0)
         {
             b1=s[i]; ile1++;
         }
         else b2=s[i];
     }
 }
 string a[2];
 string b[2];
 a[0]=a1;
 a[1]=a2;
 b[0]=b1;
 b[1]=b2;
 for(int i=0;i<2;i++)
 {
     for(int j=0;j<2;j++)
     {
         vector<char> ans=zrob(a[i]+b[j]);
         if(XD==1)
         {
             for(int i=0;i<ans.size();i++) cout<<ans[i];
             return 0;
         }
     }
 }
  for(int i=0;i<2;i++)
 {
     for(int j=0;j<2;j++)
     {
         vector<char> ans=zrob(b[i]+a[j]);
         if(XD==1)
         {
             for(int i=0;i<ans.size();i++) cout<<ans[i];
             return 0;
         }
     }
 }

    return 0;
}
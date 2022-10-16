#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
   int n; cin>>n;
   string s,t; cin>>s>>t;
   string a='0'+s;
   string b='0'+t;
   int ile=0;
   for(int i=1;i<=n/2;i++)
   {
       int wynik=0;
       char a1=a[i];
       char a2=a[n+1-i];
       char b1=b[i];
       char b2=b[n+1-i];
       if(a1>a2) swap(a1,a2);
       if(b1>b2) swap(b1,b2);
       vector<char> xd;
       xd.push_back(a1); xd.push_back(a2); xd.push_back(b1); xd.push_back(b2);
       sort(xd.begin(),xd.end());
       if(xd[0]==xd[1] && xd[2]==xd[3]) wynik=0;
       else if(a1==a2)
       {
           if(b1==a1 || b2==a1) wynik=1;
           else wynik=2;
       }
       else
       {
           if(xd[0]==xd[1] || xd[1]==xd[2] || xd[2]==xd[3]) wynik=1;
           else wynik=2;
       }
       ile+=wynik;

       //cout<<i<<" "<<ile<<endl;
   }
   if(n%2==1)
   {
       if(a[n/2+1]!=b[n/2+1]) ile++;
   }
   cout<<ile<<endl;

    return 0;
}
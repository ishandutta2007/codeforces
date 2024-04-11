#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{

   string s; cin>>s;
   int k; cin>>k;
   int a,b; a=0; b=0;
   for(int i=0;i<s.length();i++)
   {
       if(s[i]=='?') a++;
       if(s[i]=='*') b++;
   }
   int ile=s.length()-a-b;
   vector<bool> czy(10000,false);
   if(ile>k)
   {
        ile-=k;
        string ans="";
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]=='?' || s[i]=='*') continue;
            if(s[i+1]=='?' || s[i+1]=='*')
            {
                if(ile>0) {ile--; continue;}
                else ans+=s[i];
            }
            else ans+=s[i];
        }
        if(s[s.length()-1]!='?' && s[s.length()-1]!='*') ans+=s[s.length()-1];
        else
        {
            if(ile>=2) {cout<<"Impossible"; return 0;}
            if(ile==0) {cout<<ans; return 0;}
            for(int i=0;i<ans.length()-1;i++)
            {
                cout<<ans[i];
            }
        }
        if(ile==0) cout<<ans;
        else cout<<"Impossible";
        return 0;
   }
   if(ile==k)
   {
       string ans="";
       for(int i=0;i<s.length();i++)
       {
           if(s[i]!='*' && s[i]!='?') ans+=s[i];
       }
       cout<<ans<<endl;
       return 0;
   }
   if(ile<k)
   {
       ile=k-ile;
       string ans="";
       if(b==0) {cout<<"Impossible"; return 0;}
       else
       {

           bool czy=true;
           for(int i=0;i<s.length();i++)
           {
               if(s[i]=='?') continue;
               else if(s[i]=='*' && czy==true)
               {
                   while(ile>0)
                   {
                       ans+=s[i-1];
                       ile--;
                   }
                   czy=false;
               }
               else if(s[i]=='*') continue;
               else ans+=s[i];
           }
       }
       cout<<ans; return 0;
   }
    return 0;
}
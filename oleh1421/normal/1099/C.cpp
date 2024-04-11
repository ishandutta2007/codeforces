#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000001];
int main()
{
   string s;cin>>s;
   int k;cin>>k;
   int m=0;
   int maxx=0;
   for (auto i:s) {
        if (i=='?'){
            maxx++;
            m++;
        } else if (i=='*'){
            maxx=k+1;
            m++;
        }
   }
   int n=(int)s.size()-2*m;
   if (n>k || n+maxx<k){
      cout<<"Impossible";
      return 0;
   }
   vector<string>v((int)s.size(),"");
   for (int i=0;i<s.size();i++) {
        v[i]+=s[i];
        if (s[i]=='?' || s[i]=='*') v[i-1]="";
   }
   for (int i=0;i<s.size();i++){
       if (s[i]=='?'){
           v[i-1]+=s[i-1];
           n++;
       } else if (s[i]=='*'){
           while (n<k){
                v[i-1]+=s[i-1];
                n++;
           }
       }
       if (n==k) break;
   }
   string res="";
   for (int i=0;i<s.size();i++){
       if (s[i]=='?' || s[i]=='*') continue;
       res+=v[i];
   }
   cout<<res;
   return 0;
}
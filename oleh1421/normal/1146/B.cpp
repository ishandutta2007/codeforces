#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool used[200001];
int main()
{
   string t;cin>>t;
   int cnt=0;
   for (auto i:t) cnt+=(i=='a');
   if ((t.size()+cnt)%2){
      cout<<":(";
      return 0;
   }
   int n=((int)t.size()+cnt)/2;
   string s="";
   for (int i=0;i<n;i++){
       s+=t[i];
   }
   string s1="";
   for (int i=0;i<n;i++){
       if (t[i]!='a') s1+=t[i];
   }
   if (s+s1==t) cout<<s;
   else cout<<":(";
   return 0;
}
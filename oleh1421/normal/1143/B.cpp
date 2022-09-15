#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
   int n;cin>>n;
   vector<int>a;
   while (n){
      a.push_back(n%10);
      n/=10;
   }
   reverse(a.begin(),a.end());
   ll maxx=1ll;
   for (int i=0;i<a.size();i++){
        //cout<<a[i]<<endl;
       ll s=1ll;
       for (int j=0;j<i;j++) s*=a[j]*1ll;
       if (a[i]-1) s*=a[i]-1ll;
       for (int j=i+1;j<a.size();j++) s*=9ll;
       maxx=max(maxx,s);
   }
   ll s=1ll;
   for (int i=0;i<a.size();i++) s*=a[i]*1ll;
   cout<<max(maxx,s);
   return 0;
}

/*
7 4
4 7 4 1 2 4 2
*/
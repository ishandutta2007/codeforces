#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[200001];
ll s[2];
int main()
{
   int n;cin>>n;
   for (int i=1;i<=n;i++){
       cin>>a[i];
       s[a[i]]++;
   }
   if (s[0]==0 || s[1]==0){
       cout<<0;
       return 0;
   }
   for (int i=1;i<=n;i++){
       s[a[i]]--;
       if (s[0]==0 || s[1]==0) {
          cout<<i;
          return 0;
       }
   }

   return 0;
}

/*
7 4
4 7 4 1 2 4 2
*/
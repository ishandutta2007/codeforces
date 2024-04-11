#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[2001];
int cnt[2];
int main()
{
   int n;cin>>n;
   vector<int>v;
   for (int i=1;i<=n;i++){
      int a;cin>>a;
      cnt[a%2]++;
      v.push_back(a);
   }
   sort(v.begin(),v.end());
   if (abs(cnt[0]-cnt[1])<=1){
      cout<<0;
      return 0;
   }
   int s=0;
   if (cnt[0]>cnt[1]){
      int t=0;
      for (int i=0;i<v.size();i++){
          if (v[i]%2==0) {
                s+=v[i];
                t++;
          }
          if (t==cnt[0]-cnt[1]-1) break;
      }
   } else {
      int t=0;
      for (int i=0;i<v.size();i++){
          if (v[i]%2==1) {
                s+=v[i];
                t++;
          }
          if (t==cnt[1]-cnt[0]-1) break;
      }
   }
   cout<<s;

   return 0;
}

/*
7 4
4 7 4 1 2 4 2
*/
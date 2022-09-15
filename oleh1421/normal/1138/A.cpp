#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100001];

int main()
{
   int n;cin>>n;
   for (int i=1;i<=n;i++) cin>>a[i];
   int cnt=1;
   vector<int>v;
   for (int i=2;i<=n;i++){
       if (a[i]==a[i-1]) {
          cnt++;
       } else {
          v.push_back(cnt);
          cnt=1;
       }
   }
   v.push_back(cnt);
   int res=2;
   for (int i=0;i<((int)v.size())-1;i++){
       res=max(res,2*min(v[i],v[i+1]));
   }
   cout<<res;
   return 0;
}

/*
7 4
4 7 4 1 2 4 2
*/
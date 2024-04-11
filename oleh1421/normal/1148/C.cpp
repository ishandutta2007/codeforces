#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300001];
int pos[300001];
int32_t main() {
   int n;cin>>n;
   for (int i=1;i<=n;i++) cin>>a[i];
   for (int i=1;i<=n;i++) pos[a[i]]=i;
   vector<pair<int,int> >ans;
   for (int i=1;i<=n;i++){
       int cur=pos[i];
       if (i==cur) continue;
       if (2*abs(i-cur)>=n) ans.push_back({i,cur});
       else if (i<=n/2 && cur<=n/2){
          ans.push_back({i,n});
          ans.push_back({cur,n});
          ans.push_back({i,n});
       } else if (i>n/2 && cur>n/2){
          ans.push_back({1,i});
          ans.push_back({1,cur});
          ans.push_back({1,i});
       } else if (i<=n/2 && cur>n/2){
          ans.push_back({i,n});
          ans.push_back({1,cur});
          ans.push_back({1,n});
          ans.push_back({1,cur});
          ans.push_back({i,n});
       } else {
          ans.push_back({cur,n});
          ans.push_back({1,i});
          ans.push_back({1,n});
          ans.push_back({1,i});
          ans.push_back({cur,n});
       }
      // ans.push_back({0,0});
       swap(a[i],a[cur]);
       swap(pos[a[i]],pos[a[cur]]);
   }
   cout<<ans.size()<<endl;
   for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;
   return 0;
}
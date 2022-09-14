#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
pair<int,int> a[200001];
bool ok(int j){
    vector<int>v;
    for (int i=1;i<=n;i++){
        if (i==j) continue;
        v.push_back(a[i].first);
    }
    vector<int>u;
    for (int i=0;i<n-1;i++){
        u.push_back(v[i+1]-v[i]);
    }
    for (int i=1;i<n-2;i++){
        if (u[i]!=u[0]) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   cin>>n;
   for (int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
   sort(a+1,a+n+1);
   vector<int>v;
   for (int i=2;i<=n;i++) v.push_back(a[i].first-a[i-1].first);
   vector<int>random={1,2};
   for (int i=1;i<n-1;i++){
       if (v[i]!=v[0]) {
            random.push_back(i+1);
            random.push_back(i+2);
       }
       if (random.size()>10) break;
   }
   for (auto i:random){
       if (ok(i)){
          cout<<a[i].second;
          return 0;
       }
   }
   cout<<-1;
   return 0;
}
/*
9 12
3 2 4 1 5 6 3 6 8
0 0 0 0 1 2 3 4 6
*/
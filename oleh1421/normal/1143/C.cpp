#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int>g[100001];
int c[100001];
int main()
{
   int n;cin>>n;
   int root=0;
   for (int i=1;i<=n;i++){
       int p;cin>>p;
       if (p==-1) root=i;
       else g[p].push_back(i);
       cin>>c[i];
       c[i]=(c[i]+1)%2;
   }
   vector<int>ans;
   for (int i=1;i<=n;i++){
       if (i==root) continue;
       int s=c[i];
       for (auto to:g[i]) s+=c[to];
       if (s==0) ans.push_back(i);
   }
   if (ans.size()==0) {
      cout<<-1;
      return 0;
   }
   for (auto i:ans) cout<<i<<" ";
   return 0;
}

/*
7 4
4 7 4 1 2 4 2
*/
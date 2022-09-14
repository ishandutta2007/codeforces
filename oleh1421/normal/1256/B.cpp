#include <bits/stdc++.h>
#define hash yugyhiui
typedef long long ll;
using namespace std;
const long long mod=991987651ll;
int p[155];
int pos[155];
void go(int l,int r){
   int x=p[r];
   for (int i=r;i>=l+1;i--) p[i]=p[i-1];
   p[l]=x;
   for (int i=l;i<=r;i++) pos[p[i]]=i;
}
void solve(){
   int n;cin>>n;
   for (int i=1;i<=n;i++) cin>>p[i],pos[p[i]]=i;
   int cur=1;
   for (int i=1;i<=n;i++){
      if (pos[i]>=cur){
         int last=cur;
         cur=pos[i];
         go(last,pos[i]);
         cur=max(cur,last+1);
      }
   }
   for (int i=1;i<=n;i++) cout<<p[i]<<" ";
   cout<<endl;

}
int main()
{
   int tt;cin>>tt;
   while (tt--){
      solve();
   }
   return 0;
}
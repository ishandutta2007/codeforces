#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int L=38;
ll a[L+10];
int main(){
  /*ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);*/
  int tt;cin>>tt;
  a[0]=1ll;
  for (int i=1;i<=L;i++) a[i]=(a[i-1]*3ll);
  while (tt--){
    ll n;cin>>n;
    vector<int>v;
    ll x=n;
    for (int i=L;i>=0;i--){
        v.push_back(n/a[i]);
        n%=a[i];
    }
    reverse(v.begin(),v.end());
    while (!v.empty() && v.back()==0) v.pop_back();
    int last = -1;
    for (int i=0;i<v.size();i++){
        if (v[i]==2) last=i;
    }
    if (last==-1) {
      cout<<x<<endl;
      continue;
    }
    int fi=-1;
    v.push_back(0);
    for (int i=last;i<v.size();i++){
        if (v[i]==0) {
          fi=i;
          break;
        }
    }
    v[fi]=1;
    for (int i=0;i<fi;i++) v[i]=0;
    ll res=0ll;
    for (int i=0;i<v.size();i++) res+=(a[i]*v[i])*1ll;
    cout<<res<<endl;
    

  }
  return 0;
}
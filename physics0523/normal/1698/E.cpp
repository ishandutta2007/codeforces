#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,s;
    cin >> n >> s;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){cin >> a[i];}
    vector<int> b(n+1);
    vector<int> unfix(n+1,1);
    for(int i=1;i<=n;i++){
      cin >> b[i];
      if(b[i]!=-1){unfix[b[i]]=0;}
    }

    unfix[0]=0;

    long long res=1;
    for(int i=1;i<=n;i++){
      if(b[i]!=-1){
        if(a[i]>b[i]+s){res=0;}
      }
    }
    vector<int> targ(n+1,0);
    for(int i=1;i<=n;i++){
      if(b[i]==-1){targ[a[i]]=1;}
    }
    
    int pt=n;
    long long ce=0;
    for(int i=n;i>=1;i--){
      while(pt>=i-s && pt>=1){
        ce+=unfix[pt];
        pt--;
      }
      if(targ[i]){res*=ce;res%=mod;ce--;}
    }
    cout << res << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q,mod;
  cin >> n >> q >> mod;

  vector<int> fib(n+5,0);
  fib[0]=1%mod;fib[1]=1%mod;
  for(int i=2;i<n+5;i++){fib[i]=(fib[i-1]+fib[i-2])%mod;}

  vector<int> c(n+5,0);
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    c[i]+=v;c[i]%=mod;
  }
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    c[i]+=(mod-v);c[i]%=mod;
  }

  vector<int> d(n+5,0);
  d[0]=c[0];
  d[1]=(mod+c[1]-c[0])%mod;
  for(int i=2;i<n+5;i++){
    d[i]=c[i]-c[i-1]-c[i-2];
    while(d[i]<0){d[i]+=mod;}
    d[i]%=mod;
  }

  int dif=0;
  for(int i=0;i<n+5;i++){if(d[i]){dif++;}}
  //for(int i=0;i<n+5;i++){cout << d[i] << ' ';}cout << '\n';

  while(q>0){
    q--;
    string typ;
    int l,r;
    cin >> typ >> l >> r;
    l--;r--;
    int las=r-l;

    if(d[l]){dif--;}
    if(typ=="A"){d[l]+=1;d[l]%=mod;}
    else{d[l]+=(mod-1);d[l]%=mod;}
    if(d[l]){dif++;}

    if(d[r+1]){dif--;}
    if(typ=="A"){d[r+1]+=(mod-fib[las+1]);d[r+1]%=mod;}
    else{d[r+1]+=fib[las+1];d[r+1]%=mod;}
    if(d[r+1]){dif++;}

    if(d[r+2]){dif--;}
    if(typ=="A"){d[r+2]+=(mod-fib[las]);d[r+2]%=mod;}
    else{d[r+2]+=fib[las];d[r+2]%=mod;}
    if(d[r+2]){dif++;}

    //for(int i=0;i<n+5;i++){cout << d[i] << ' ';}cout << '\n';
    if(dif==0){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
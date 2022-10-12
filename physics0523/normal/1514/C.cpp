#include<bits/stdc++.h>

using namespace std;

long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> v;

  v.push_back(-1);
  for(long long i=1;i<n;i++){
    if(llgcd(n,i)==1){v.push_back(i);}
  }

  int vs=v.size()-1;
  vector<long long> lp(vs+5),rp(vs+5);
  lp[1]=v[1];
  for(int i=2;i<=vs;i++){lp[i]=(lp[i-1]*v[i])%n;}
  rp[vs]=v[vs];
  for(int i=vs-1;i>=1;i--){rp[i]=(rp[i+1]*v[i])%n;}

  if(lp[vs]==1){
    cout << vs << '\n';
    for(int i=1;i<=vs;i++){
      if(i!=1){cout << ' ';}
      cout << v[i];
    }
    cout << '\n';
    return 0;
  }
  lp[0]=1;rp[vs+1]=1;
  for(int i=1;i<=vs;i++){
    if((lp[i-1]*rp[i+1])%n==1){
      cout << vs-1 << '\n';
      bool fl=false;
      for(int j=1;j<=vs;j++){
        if(i==j){continue;}
        if(fl){cout << ' ';}fl=true;
        cout << v[j];
      }cout << '\n';
      return 0;
    }
  }
  return 0;
}
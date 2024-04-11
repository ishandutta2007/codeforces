#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;

bool is(long long p,long long st,long long fi){
  if(min(st,fi)<=p && p<=max(st,fi)){return true;}
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> t(n+2),x(n+2);
    t[0]=0;x[0]=0;
    for(int i=1;i<=n;i++){
      cin >> t[i] >> x[i];
    }
    t[n+1]=llinf;
    long long cx=0,ce=0;
    long long res=0;
    for(int i=1;i<=n;i++){
      if(cx==ce){ce=x[i];}
      long long st=cx;
      long long fi;
      if(abs(ce-cx)<=t[i+1]-t[i]){fi=ce;}
      else{
        long long d;
        if(cx<ce){
          fi=cx+(t[i+1]-t[i]);
        }
        else{
          fi=cx-(t[i+1]-t[i]);
        }
      }
      if(is(x[i],st,fi)){res++;}
      cx=fi;
    }
    cout << res << '\n';
  }
  return 0;
}
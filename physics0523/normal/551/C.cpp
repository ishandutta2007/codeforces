#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m;
  cin >> n >> m;
  vector<long long> a(n+1,0);
  long long st=0,fi=1e15;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    if(a[i]>0){st=i;}
  }
  while(st<=fi){
    long long te=(st+fi)/2;
    vector<long long> ca=a;
    long long pt=n;
    for(int i=0;i<m;i++){
      long long cnt=0;
      while(pt>=1 && ca[pt]==0){pt--;}
      long long spt=pt;
      while(pt>=1){
        if(cnt+spt+ca[pt]<=te){
          cnt+=ca[pt];
          ca[pt]=0;
          pt--;
        }
        else{
          long long del=max(0ll,te-spt-cnt);
          ca[pt]-=del;
          break;
        }
      }
    }
    bool isok=true;
    for(auto &nx : ca){
      if(nx){isok=false;break;}
    }
    if(isok){fi=te-1;}
    else{st=te+1;}
  }
  cout << st << '\n';
  return 0;
}
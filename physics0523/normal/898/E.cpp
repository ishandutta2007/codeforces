#include<bits/stdc++.h>

using namespace std;

int sq(int x){
  int st=0,fi=40000,te;
  while(st<=fi){
    te=(st+fi)/2;
    if(te*te<=x){st=te+1;}
    else{fi=te-1;}
  }
  return fi;
}

long long llzt(long long a,long long b){return max(a,b)-min(a,b);}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  long long res=0;
  vector<long long> del;
  for(int i=0;i<n;i++){
    long long v;
    cin >> v;
    long long csq=sq(v);
    if(v==0){del.push_back(2);}
    else if(csq*csq==v){del.push_back(1);}
    else{
      res+=min(llzt(csq*csq,v),llzt((csq+1)*(csq+1),v));
      del.push_back(-min(llzt(csq*csq,v),llzt((csq+1)*(csq+1),v)));
    }
  }
  sort(del.begin(),del.end());
  for(int i=0;i<(n/2);i++){res+=del[i];}
  cout << res << '\n';
  return 0;
}
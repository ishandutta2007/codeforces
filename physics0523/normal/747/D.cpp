#include<bits/stdc++.h>

using namespace std;

int grd(vector<int> v,int x){
  int n=v.size();
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++){
    if(v[i]>x){return i;}
    x-=v[i];
  }
  return n;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  int nk=0;
  vector<int> a(n+1);
  a[0]=0;
  for(int i=1;i<=n;i++){
    int v;
    cin >> v;
    if(v>=0){a[i]=0;}
    else{a[i]=1;nk++;}
  }
  if(k<nk){cout << "-1\n";return 0;}
  int res=0;
  for(int i=0;i<n;i++){
    if(a[i]!=a[i+1]){res++;}
  }
  if(res==0){cout << "0\n";return 0;}

  int fm=0;
  for(int i=0;i<=n;i++){if(a[i]==1){fm=i;break;}}
  vector<int> zseg;
  int cz=0;
  for(int i=fm;i<=n;i++){
    if(a[i]==1){
      if(cz>0){zseg.push_back(cz);}
      cz=0;
    }
    else{cz++;}
  }
  int dlt=2*grd(zseg,k-nk);
  if(cz>0 && (k-nk)>=cz){dlt=max(dlt,1+2*grd(zseg,k-nk-cz));}
  cout << res-dlt << '\n';
  return 0;
}
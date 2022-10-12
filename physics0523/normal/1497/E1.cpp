#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;

int ssize=524288;
int stree[1048576],vd=inf;

void sinit(){
  int i,j;
  for(i=0;i<2*ssize;i++){
    stree[i]=inf;
  }
}

void upd(int k,int a){
  int i,m;
  int ld,rd,md;
  k+=ssize-1;
  stree[k]=a;
  while(k>0){
    k=(k-1)/2;
    ld=stree[2*k+1];
    rd=stree[2*k+2];
    md=min(ld,rd);
    stree[k]=md;
  }
}

//calc min[a,b)
//call:k=0,l=0,r=ssize
int query(int a,int b,int k,int l,int r){
  int ld,rd,md;
  if(r<=a || b<=l){return vd;}
  if(a<=l && r<=b){return stree[k];}
  else{
    ld=query(a,b,k*2+1,l,(l+r)/2);
    rd=query(a,b,k*2+2,(l+r)/2,r);
    md=min(ld,rd);
    return md;
  }
}

int main(){
  sinit();
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  vector<int> hv(10000005,1);
  vector<bool> fl(10000005,false);
  for(int i=2;i<10000005;i++){
    if(fl[i]){continue;}
    for(int j=i;j<10000005;j+=i){
      fl[j]=true;
      int cnt=0,cv=j;
      while(cv%i==0){cv/=i;cnt++;}
      if(cnt%2==1){hv[j]*=i;}
    }
  }

  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=1;i<=n;i++){upd(i,inf);}
    upd(0,0);
    for(int i=0;i<n;i++){
      cin >> a[i];
      a[i]=hv[a[i]];
    }
    int st=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
      mp[a[i]]++;
      while(mp[a[i]]>=2){mp[a[st]]--;st++;}
      int v=query(st,i+1,0,0,ssize);
      upd(i+1,v+1);
    }
    cout << query(n,n+1,0,0,ssize) << '\n';
  }
  return 0;
}
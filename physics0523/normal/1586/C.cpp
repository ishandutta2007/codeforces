#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;

long long ssize=1048576;
long long stree[2097152],vd=-inf;

void sinit(){
  long long i,j;
  for(i=0;i<2*ssize;i++){stree[i]=-inf;}
}

void upd(long long k,long long a){
  long long i,m;
  long long ld,rd,md;
  k+=ssize-1;
  stree[k]=a;
  while(k>0){
    k=(k-1)/2;
    ld=stree[2*k+1];
    rd=stree[2*k+2];
    md=max(ld,rd);
    stree[k]=md;
  }
}

//calc min[a,b)
//call:k=0,l=0,r=ssize
long long query(long long a,long long b,long long k,long long l,long long r){
    long long ld,rd,md;
    long long i,lp,rp;
    if(r<=a || b<=l){return vd;}
    if(a<=l && r<=b){return stree[k];}
    else{
        ld=query(a,b,k*2+1,l,(l+r)/2);
        rd=query(a,b,k*2+2,(l+r)/2,r);
        md=max(ld,rd);
        return md;
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  for(auto &nx : s){cin >> nx;}
  vector<vector<int>> arr(n,vector<int>(m,inf));
  for(int j=0;j<m;j++){
    arr[0][j]=-inf;
    if(j==0){
      for(int i=0;i<n;i++){
        arr[i][j]=-inf;
      }
    }
    else{
      for(int i=0;i<n;i++){
        if(s[i][j-1]=='X'){arr[i][j]=min(arr[i][j],j);}
        else{arr[i][j]=min(arr[i][j],min(arr[i][j-1],j));}
      }
    }
    for(int i=1;i<n;i++){
      if(s[i-1][j]=='.'){arr[i][j]=min(arr[i-1][j],arr[i][j]);}
    }
  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++){cout << arr[i][j] << ' ';}cout << '\n';
  // }
  sinit();
  for(int j=0;j<m;j++){
    int cd=-inf;
    for(int i=0;i<n;i++){cd=max(cd,arr[i][j]);}
    upd(j,cd);
  }
  int q;
  cin >> q;
  while(q>0){
    q--;
    int l,r;
    cin >> l >> r;
    l--;r--;
    int val=query(l,r+1,0,0,ssize);
    if(val>l){cout << "NO\n";}else{cout << "YES\n";}
  }
  return 0;
}
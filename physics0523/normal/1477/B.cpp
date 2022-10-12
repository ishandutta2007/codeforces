#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;

int ssize=262144;
int stree[524288],lazy[524288],vd=0;

void sinit(){
    int i,j;
    for(i=0;i<2*ssize;i++){
        stree[i]=0;
        lazy[i]=-inf;
    }
    return;
}

//lazy evaluation
void eval(int k){
  if(lazy[k]!=-inf){
    stree[k]=lazy[k];
    if(k<(ssize-1)){
      lazy[2*k+1]=(lazy[k]/2);
      lazy[2*k+2]=(lazy[k]/2);
    }
    lazy[k]=-inf;
  }
  return;
}

//set t [a,b)
//call:k=0,l=0,r=ssize
void setquery(int a,int b,int t,int k,int l,int r){
    int ld,rd,md;
    eval(k);
    if(r<=a || b<=l){return;}
    if(a<=l && r<=b){
        lazy[k]=(t*(r-l));
        eval(k);
        return;
    }
    else{
        eval(k*2+1);
        eval(k*2+2);
        setquery(a,b,t,k*2+1,l,(l+r)/2);
        setquery(a,b,t,k*2+2,(l+r)/2,r);
        stree[k]=(stree[k*2+1]+stree[k*2+2]);
        lazy[k]=-inf;
        return;
    }
}

//calc sum[a,b)
//call:k=0,l=0,r=ssize
int sumquery(int a,int b,int k,int l,int r){
    int ld,rd,md;
    eval(k);
    if(r<=a || b<=l){return vd;}
    if(a<=l && r<=b){
        return stree[k];
    }
    else{
        ld=sumquery(a,b,k*2+1,l,(l+r)/2);
        rd=sumquery(a,b,k*2+2,(l+r)/2,r);
        md=ld+rd;
        return md;
    }
}

int main(){
  sinit();
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,q;
    cin >> n >> q;
    string s;
    string f;
    cin >> s >> f;
    vector<int> l(q),r(q);
    for(int i=0;i<q;i++){
      cin >> l[i] >> r[i];
      l[i]--;r[i]--;
    }
    for(int i=0;i<n;i++){
      if(f[i]=='1'){setquery(i,i+1,1,0,0,ssize);}
      else{setquery(i,i+1,0,0,0,ssize);}
    }
    int fl=1;
    for(int i=q-1;i>=0;i--){
      int sl=r[i]-l[i]+1;
      int v=sumquery(l[i],r[i]+1,0,0,ssize);
      //cerr << sl << ' ' << v << ':'; 
      if(v*2>sl){
        //cerr << 1 << '\n';
        setquery(l[i],r[i]+1,1,0,0,ssize);
      }
      else if(v*2==sl){fl=0;break;}
      else{
        //cerr << 0 << '\n';
        setquery(l[i],r[i]+1,0,0,0,ssize);
      }
    }
    
    if(fl==1){
      for(int i=0;i<n;i++){
        int v=sumquery(i,i+1,0,0,ssize);
        if((s[i]-'0')!=v){fl=0;}
      }
    }
    if(fl==1){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
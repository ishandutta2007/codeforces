#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;
using pi=pair<int,int>;

int ssize=524288;
pi stree[1048576];

#define con max

pi vd=make_pair(-inf,-inf);

void sinit(){
  for(int i=0;i<2*ssize;i++){stree[i]=vd;}
}

void upd(int k,pi a){
  k+=ssize-1;
  stree[k]=a;
  while(k>0){
    k=(k-1)/2;
    stree[k]=con(stree[2*k+1],stree[2*k+2]);
  }
}

// [a,b)
// call:k=0,l=0,r=ssize
pi query(int a,int b,int k,int l,int r){
  if(r<=a || b<=l){return vd;}
  if(a<=l && r<=b){return stree[k];}
  else{return con(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));}
}

//Binary Indexed Tree
int bit[525252]={0},bsize=524288;
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&(-i);
    }
    return s;
}
void add(int i,int x){
    while(i<=bsize){
        bit[i]+=x;
        i+=i&(-i);
    }
}

#define key 120000

int main(){
  sinit();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  string s;
  cin >> n >> s >> m;
  for(int i=1;i<=n;i++){
    if(s[i-1]=='a'){
      if(i%2){add(key+i,1);}
      else{add(i,1);}
    }
    if(s[i-1]=='b'){
      if(i%2){add(i,1);}
      else{add(key+i,1);}
    }
    if(s[i-1]=='?'){
      add(2*key+i,1);
    }
  }
  upd(0,make_pair(0,0));
  for(int i=m;i<=n;i++){
    int st=i-m+1;
    if(st%2){
      if(sum(i)-sum(st-1)){continue;}
    }
    else{
      if(sum(key+i)-sum(key+st-1)){continue;}
    }
    pi cv=query(0,st,0,0,ssize);
    //cout << i << ' ' << cv.first << ' ' << cv.second << '\n';
    int uk=sum(2*key+i)-sum(2*key+st-1);
    cv.first++;
    cv.second-=uk;
    upd(i,cv);
    //cout << i << ' ' << cv.first << ' ' << cv.second << '\n';
  }
  cout << -query(0,ssize,0,0,ssize).second << '\n';
  return 0;
}
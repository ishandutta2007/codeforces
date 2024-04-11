#include<bits/stdc++.h>

using namespace std;

long long ssize=524288;
long long stree[1048576],lazy[1048576];

void sinit(){
    long long i,j;
    for(i=0;i<2*ssize;i++){
        stree[i]=0;
        lazy[i]=0;
    }
    return;
}

//lazy evaluation
void eval(long long k){
  if(lazy[k]!=0){
    stree[k]=max(stree[k],lazy[k]);
    if(k<(ssize-1)){
      lazy[2*k+1]=max(lazy[2*k+1],lazy[k]);
      lazy[2*k+2]=max(lazy[2*k+2],lazy[k]);
    }
    lazy[k]=0;
  }
  return;
}

//spread t [a,b)
//call:k=0,l=0,r=ssize
void sprquery(long long a,long long b,long long t,long long k,long long l,long long r){
    if(r<=a){return;}
    if(b<=l){return;}
    long long ld,rd,md;
    eval(k);
    if(a<=l && r<=b){
        lazy[k]=max(lazy[k],t);
        eval(k);
        return;
    }
    //eval(k*2+1);
    //eval(k*2+2);
    sprquery(a,b,t,k*2+1,l,(l+r)/2);
    sprquery(a,b,t,k*2+2,(l+r)/2,r);
    stree[k]=max(stree[k*2+1],stree[k*2+2]);
    lazy[k]=0;
}

//calc max[a,b)
//call:k=0,l=0,r=ssize
long long maxquery(long long a,long long b,long long k,long long l,long long r){
    if(r<=a){return 0;}
    if(b<=l){return 0;}
    eval(k);
    if(a<=l && r<=b){
        return stree[k];
    }
    else{
        return max(
          maxquery(a,b,k*2+1,l,(l+r)/2),
          maxquery(a,b,k*2+2,(l+r)/2,r)
        );
    }
}

int main(){
  sinit();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  vector<long long> h(n);
  set<int> st;
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i] >> h[i];
    st.insert(a[i]);
    st.insert(b[i]);
  }
  unordered_map<long long,int> mp;
  int pt=0;
  for(auto &nx : st){
    mp[nx]=pt;
    pt++;
  }
  vector<pair<pair<int,int>,long long>> rv;
  for(int i=0;i<n;i++){rv.push_back(make_pair(make_pair(mp[b[i]],mp[a[i]]),h[i]));}
  sort(rv.begin(),rv.end());
  reverse(rv.begin(),rv.end());

  for(int i=0;i<n;i++){
    long long cv=maxquery(rv[i].first.first,rv[i].first.first+1,0,0,ssize);
    sprquery(rv[i].first.second+1,rv[i].first.first+1,cv+rv[i].second,0,0,ssize);
  }
  cout << maxquery(0,ssize,0,0,ssize) << '\n';
  return 0;
}
#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;

int ssize=524288;
int stree[1048576],vd=-inf;

void sinit(){
  int i,j;
  for(i=0;i<2*ssize;i++){stree[i]=-inf;}
}

void upd(int k,int a){
  int i,m;
  int ld,rd,md;
  k+=ssize-1;
  stree[k]=max(a,stree[k]);
  while(k>0){
    k=(k-1)/2;
    ld=stree[2*k+1];
    rd=stree[2*k+2];
    md=max(ld,rd);
    stree[k]=md;
  }
}

//calc max[a,b)
//call:k=0,l=0,r=ssize
int query(int a,int b,int k,int l,int r){
  int ld,rd,md;
  if(r<=a || b<=l){return vd;}
  if(a<=l && r<=b){return stree[k];}
  else{
    ld=query(a,b,k*2+1,l,(l+r)/2);
    rd=query(a,b,k*2+2,(l+r)/2,r);
    md=max(ld,rd);
    return md;
  }
}

void comp(vector<int> &inp){
  int n=inp.size();
  set<int> st;
  for(int i=0;i<n;i++){st.insert(inp[i]);}
  int cnt=0;
  unordered_map<int,int> mp;
  for(auto &nx : st){
    mp[nx]=cnt;
    cnt++;
  }
  for(int i=0;i<n;i++){inp[i]=mp[inp[i]];}
}

using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  sinit();
  int n;
  cin >> n;
  vector<int> be(n),in(n),ri(n);
  for(int i=0;i<n;i++){cin >> be[i];}
  for(int i=0;i<n;i++){cin >> in[i];}
  for(int i=0;i<n;i++){cin >> ri[i];}
  comp(be);comp(in);comp(ri);
  //for(int i=0;i<n;i++){cout << be[i] << ' ';}cout << '\n';
  //for(int i=0;i<n;i++){cout << in[i] << ' ';}cout << '\n';
  //for(int i=0;i<n;i++){cout << ri[i] << ' ';}cout << '\n';
  vector<pair<int,pi>> v;
  for(int i=0;i<n;i++){v.push_back(make_pair(be[i],make_pair(in[i],ri[i])));}
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  
  int p=0,res=0;
  for(int i=0;i<n;i++){
    while(v[p].first>v[i].first){
      upd(v[p].second.first,v[p].second.second);
      p++;
    }
    int tg=query(v[i].second.first+1,ssize,0,0,ssize);
    if(tg>v[i].second.second){res++;}
  }
  cout << res << '\n';
  return 0;
}
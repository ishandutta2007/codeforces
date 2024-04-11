#include<bits/stdc++.h>

using namespace std;

int d(vector<int> &a,vector<int> &b,int n){
  int res=0;
  for(int i=1;i<=n;i++){
    if(a[i]!=b[i]){res++;}
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n+1),q(n+1),r(n+1,0);
  for(int i=1;i<=n;i++){cin >> p[i];}
  for(int i=1;i<=n;i++){cin >> q[i];}
  set<int> st;
  for(int i=1;i<=n;i++){st.insert(i);}
  for(int i=1;i<=n;i++){
    if(p[i]==q[i]){
      r[i]=p[i];
      st.erase(r[i]);
    }
  }
  vector<int> rem;
  for(auto &nx : st){rem.push_back(nx);}
  do{
    int pt=0;
    vector<int> cres=r;
    for(int i=1;i<=n;i++){
      if(cres[i]==0){cres[i]=rem[pt];pt++;}
    }
    if(d(p,cres,n)==1 && d(q,cres,n)==1){
      for(int i=1;i<=n;i++){
        if(i-1){cout << ' ';}
        cout << cres[i];
      }cout << '\n';
      return 0;
    }
  }while(next_permutation(rem.begin(),rem.end()));
  return 0;
}
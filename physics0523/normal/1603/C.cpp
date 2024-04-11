#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define mod 998244353

using namespace std;
using dat=pair<int,long long>;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    reverse(a.begin(),a.end());
    long long res=0;
    vector<dat> mp;
    long long rem=a.size();
    for(auto &nx : a){
      vector<dat> np;
      for(auto &cp : mp){
        int pv=cp.first;
        long long pp=cp.second;
        //cerr << nx << ':' << pv << ' ' << pp << '\n';
        int st=ceil(nx,pv);
        long long del=((long long)(st-1))*pp;del%=mod;
        del*=rem;del%=mod;
        res+=del;res%=mod;
        int le=(nx/st);
        np.push_back({le,pp});
        //np[le]+=pp;np[le]%=mod;
      }
      np.push_back({nx,1});
      sort(np.begin(),np.end());
      int cv=-1;
      long long cp=-1;
      mp.clear();
      for(auto &nx : np){
        if(cv!=nx.first){
          if(cv!=-1){mp.push_back({cv,cp});}
          cp=nx.second;cv=nx.first;
        }
        else{cp+=nx.second;cp%=mod;}
      }
      if(cv!=-1){mp.push_back({cv,cp});}
      //np[nx]++;np[nx]%=mod;
      rem--;
    }
    cout << res%mod << '\n';
  }
  return 0;
}
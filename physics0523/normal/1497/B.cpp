#include<bits/stdc++.h>

using namespace std;

int f(int p,int q){
  if(p>q){swap(p,q);}
  return max(1,q-p);
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    unordered_map<int,int> mp;
    unordered_map<int,bool> fl;
    for(int i=0;i<n;i++){
      cin >> a[i];
      mp[a[i]%m]++;
    }
    vector<int> tg;
    for(auto &nx : mp){tg.push_back(nx.first);}
    int res=0;
    for(auto &nx : tg){
      int e1,e2;
      e1=nx;e2=m-nx;
      if(e1>e2){swap(e1,e2);}
      if(fl[e1]==true){continue;}
      fl[e1]=true;
      if(e1==0){res++;}
      else if(e1==e2){res++;}
      else{res+=f(mp[e1],mp[e2]);}
    }
    cout << res << '\n';
  }
  return 0;
}
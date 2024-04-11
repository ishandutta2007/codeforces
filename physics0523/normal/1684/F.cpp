#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
      cin >> a[i];
      mp[a[i]].push_back(i);
    }
    int id=0;
    for(auto &nx : mp){
      for(auto &ny : nx.second){a[ny]=id;}
      id++;
    }
    vector<int> las(n);
    for(int i=0;i<n;i++){las[i]=i;}
    for(int i=0;i<m;i++){
      int l,r;
      cin >> l >> r;
      l--;r--;
      las[l]=max(las[l],r);
    }
    for(int i=1;i<n;i++){las[i]=max(las[i-1],las[i]);}
    int cnt=0;
    vector<set<int>> st(n);
    for(int i=0;i<n;i++){
      if(!st[a[i]].empty()){
        auto it=st[a[i]].end();it--;
        if(las[(*it)]>=i){cnt++;}
      }
      st[a[i]].insert(i);
    }

    if(cnt==0){cout << "0\n";continue;}
    int res=n-1;
    int rp=0;
    for(int lp=0;lp<n;lp++){
      bool err=false;
      while(cnt>0){
        if(rp==n){err=true;break;}
        auto it=st[a[rp]].lower_bound(rp);
        int l=-1,r=-1;
        if(it!=st[a[rp]].begin()){
          auto cit=it;cit--;
          l=(*cit);
        }
        it++;
        if(it!=st[a[rp]].end()){
          r=(*it);
        }

        if(l!=-1){
          if(las[l]>=rp){cnt--;}
        }
        if(r!=-1){
          if(las[rp]>=r){cnt--;}
        }
        if(l!=-1 && r!=-1){
          if(las[l]>=r){cnt++;}
        }
        st[a[rp]].erase(rp);
        rp++;
      }
      if(err){break;}
      res=min(res,rp-lp);

      st[a[lp]].insert(lp);
      auto it=st[a[lp]].lower_bound(lp);
      int l=-1,r=-1;
      if(it!=st[a[lp]].begin()){
        auto cit=it;cit--;
        l=(*cit);
      }
      it++;
      if(it!=st[a[lp]].end()){
        r=(*it);
      }

      if(l!=-1){
        if(las[l]>=lp){cnt++;}
      }
      if(r!=-1){
        if(las[lp]>=r){cnt++;}
      }
      if(l!=-1 && r!=-1){
        if(las[l]>=r){cnt--;}
      }
    }

    cout << res << '\n';
  }
  return 0;
}
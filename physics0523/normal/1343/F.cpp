#include<bits/stdc++.h>

using namespace std;

int same(vector<int> &a,vector<int> &b){
  int res=0;
  int p=0,q=0;
  while(p<a.size() && q<b.size()){
    if(a[p]==b[q]){res++;p++;q++;}
    else if(a[p]<b[q]){p++;}
    else{q++;}
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<vector<int>> a(n-1);
    vector<set<int>> st(n-1);
    vector<bitset<256>> bs(n-1);
    for(int i=0;i<n-1;i++){
      int k;
      cin >> k;
      for(int j=0;j<k;j++){
        int v;
        cin >> v;
        a[i].push_back(v);
        st[i].insert(v);
        bs[i].set(v);
      }
    }

    for(int i=1;i<=n;i++){
      vector<bool> used(n-1,false);
      vector<int> res={i};
      for(int j=1;j<n;j++){
        vector<bitset<256>> prev(j+1);
        for(int k=1;k<=j;k++){
          prev[k]=prev[k-1];
          prev[k].set(res[j-k]);
        }

        bool miss=true;
        for(int k=0;k<n-1;k++){
          if(used[k]){continue;}
          if((a[k].size()-1)>j){continue;}
          if((bs[k]^prev[a[k].size()-1]).count()==1){
            set<int> cs=st[k];
            for(int l=1;l<=a[k].size()-1;l++){
              cs.erase(res[j-l]);
            }
            res.push_back((*cs.begin()));
            used[k]=true;
            miss=false;
            break;
          }
        }
        if(miss){break;}
      }
      if(res.size()==n){
        for(int j=0;j<n;j++){
          if(j){cout << ' ';}
          cout << res[j];
        }
        cout << '\n';
        break;
      }
    }
  }
  return 0;
}
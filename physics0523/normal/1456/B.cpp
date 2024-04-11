#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  int res=1e9;
  for(int i=1;i<n;i++){
    int fr=i-1,bk=i;
    int fv=0,bv=0;
    vector<pair<int,int>> fp,bp;
    for(int j=0;(fr>=0 && j<50);j++){
      fv^=a[fr];
      fp.push_back({fv,j});
      fr--;
    }
    for(int j=0;(bk<n && j<50);j++){
      bv^=a[bk];
      bp.push_back({bv,j});
      bk++;
    }
    sort(fp.begin(),fp.end());
    sort(bp.begin(),bp.end());
    // for(auto &nx : fp){cerr << nx.first << ' ' << nx.second << '\n';}
    // for(auto &nx : bp){cerr << nx.first << ' ' << nx.second << '\n';}
    for(int i=1;i<bp.size();i++){
      bp[i].second=min(bp[i].second,bp[i-1].second);
    }
    bp.push_back({2e9,2e9});
    int tg=0;
    for(int i=0;i<fp.size();i++){
      while(fp[i].first>bp[tg].first){tg++;}
      if(tg!=0){
        res=min(res,fp[i].second+bp[tg-1].second);
      }
    }
  }
  if(res>1e8){res=-1;}
  cout << res << '\n';
  return 0;
}
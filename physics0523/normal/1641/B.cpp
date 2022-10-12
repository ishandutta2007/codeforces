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
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for(auto &nx : a){
      cin >> nx;
      mp[nx]++;
    }
    bool ng=false;
    for(auto &nx : mp){
      if(nx.second%2==1){ng=true;}
    }
    if(ng){cout << "-1\n";continue;}
    vector<pi> r1;
    vector<int> r2;
    int pref=0;
    while(a.size()>=2){
      if(a.size()==2){r2.push_back(2);break;}
      int tg=-1;
      for(int i=1;i<a.size();i++){
        if(a[0]==a[i]){tg=i;break;}
      }
      vector<int> na;
      for(int i=1;i<tg;i++){
        r1.push_back({pref+tg+i,a[i]});
      }
      r2.push_back(2*tg);
      pref+=2*tg;

      for(int i=tg-1;i>=1;i--){na.push_back(a[i]);}
      for(int i=tg+1;i<a.size();i++){na.push_back(a[i]);}
      a.swap(na);
    }
    cout << r1.size() << '\n';
    for(auto &nx : r1){cout << nx.first << ' ' << nx.second << '\n';}
    cout << r2.size() << '\n';
    for(int i=0;i<r2.size();i++){
      if(i){cout << ' ';}
      cout << r2[i];
    }cout << '\n';
  }
  return 0;
}
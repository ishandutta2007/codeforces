#include<bits/stdc++.h>

using namespace std;

bool isperm(vector<int> a){
  sort(a.begin(),a.end());
  int n=a.size();
  for(int i=0;i<n;i++){
    if(a[i]!=(i+1)){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int tg=-1;
    map<int,int> mp;
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
      mp[a[i]]++;
      if(mp[a[i]]==2){tg=max(tg,a[i]);}
    }
    if(tg==-1){cout << "0\n"; continue;}
    set<pair<int,int>> st;
    vector<int> pa,pb;
    for(int i=0;i<n;i++){
      if(i<tg){pa.push_back(a[i]);}
      else{pb.push_back(a[i]);}
    }
    if(isperm(pa)&&isperm(pb)){st.insert(make_pair(tg,n-tg));}
    pa.clear();pb.clear();
    for(int i=0;i<n;i++){
      if(i<tg){pa.push_back(a[n-1-i]);}
      else{pb.push_back(a[n-1-i]);}
    }
    if(isperm(pa)&&isperm(pb)){st.insert(make_pair(n-tg,tg));}    
    cout << st.size() << '\n';
    for(auto &v : st){
      cout << v.first << ' ' << v.second << '\n';
    }
  }
}
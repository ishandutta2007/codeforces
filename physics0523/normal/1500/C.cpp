#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int tg;
bool comp(const vector<int> &a,const vector<int> &b){
  return (a[tg]<b[tg]);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  Graph a(n),b(n);

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int v;
      cin >> v;
      a[i].push_back(v);
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int v;
      cin >> v;
      b[i].push_back(v);
    }
  }

  bitset<1600> bs[m];
  for(int j=0;j<m;j++){
    for(int i=0;i<n-1;i++){
      if(b[i][j]>b[i+1][j]){bs[j][i]=true;}
    }
  }
  vector<bool> used(m);
  vector<int> ope;
  for(int t=0;t<m;t++){
    for(int i=0;i<m;i++){
      if(used[i]){continue;}
      if(bs[i].any()){continue;}
      used[i]=true;
      ope.push_back(i);
      bitset<1600> cv;
      for(int j=0;j<n-1;j++){
        if(b[j][i]==b[j+1][i]){cv[j]=true;}
      }
      for(int j=0;j<m;j++){
        if(!used[j]){bs[j]&=cv;}
      }
      break;
    }
  }
  reverse(ope.begin(),ope.end());
  for(int i=0;i<ope.size();i++){
    tg=ope[i];
    stable_sort(a.begin(),a.end(),comp);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i][j]!=b[i][j]){
        cout << "-1\n";
        return 0;
      }
    }
  }
  cout << ope.size() << '\n';
  for(int i=0;i<ope.size();i++){
    if(i){cout << ' ';}
    cout << ope[i]+1;
  }cout << '\n';
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dv={
  {1,2},{3,4},
  {1,3},{2,4},
  {1,4},{2,3},
  {2,3},{1,4},
  {2,4},{1,3},
  {3,4},{1,2}
};

int n,m;
vector<string> s;

vector<string> solve_hr(vector<int> p0,vector<int> p1){
  vector<string> res=s;
  for(int i=0;i<n;i++){
    int f0=1,f1=1;
    vector<int> cv;
    if(i%2==0){cv=p0;}
    else{cv=p1;}

    for(int j=0;j<m;j++){
      if(s[i][j]!='0'){
        if((s[i][j]-'0')!=cv[j%2]){f0=0;}
        if((s[i][j]-'0')!=cv[(j+1)%2]){f1=0;}
      }
    }

    if(f0){
      for(int j=0;j<m;j++){
        res[i][j]=('0'+cv[j%2]);
      }
    }
    else if(f1){
      for(int j=0;j<m;j++){
        res[i][j]=('0'+cv[(j+1)%2]);
      }
    }
    else{
      return {};
    }
  }
  return res;
}

vector<string> solve_vt(vector<int> p0,vector<int> p1){
  vector<string> res=s;
  for(int i=0;i<m;i++){
    int f0=1,f1=1;
    vector<int> cv;
    if(i%2==0){cv=p0;}
    else{cv=p1;}

    for(int j=0;j<n;j++){
      if(s[j][i]!='0'){
        if((s[j][i]-'0')!=cv[j%2]){f0=0;}
        if((s[j][i]-'0')!=cv[(j+1)%2]){f1=0;}
      }
    }

    if(f0){
      for(int j=0;j<n;j++){
        res[j][i]=('0'+cv[j%2]);
      }
    }
    else if(f1){
      for(int j=0;j<n;j++){
        res[j][i]=('0'+cv[(j+1)%2]);
      }
    }
    else{
      return {};
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  s.resize(n);
  for(auto &nx : s){cin >> nx;}

  for(int i=0;i<6;i++){
    vector<string> res=solve_hr(dv[2*i],dv[2*i+1]);
    if(!res.empty()){
      for(auto &nx : res){cout << nx << "\n";}
      return 0;
    }
    res=solve_vt(dv[2*i],dv[2*i+1]);
    if(!res.empty()){
      for(auto &nx : res){cout << nx << "\n";}
      return 0;
    }
  }
  cout << "0\n";
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int to_int(string s){
  int res=0;
  for(auto &nx : s){
    res*=32;
    res+=(nx-'a'+1);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  vector<int> tlis;
  for(char i='a';i<='z';i++){
    for(char j='a';j<='z';j++){
      string s;
      s.push_back(i);
      s.push_back(j);
      tlis.push_back(to_int(s));
    }
  }
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<string> s(n);
    for(auto &nx : s){cin >> nx;}
    bool isok=false;
    for(auto &nx : s){
      string rs=nx;
      reverse(rs.begin(),rs.end());
      if(nx==rs){isok=true;break;}
    }
    if(isok){cout << "YES\n";continue;}

    vector<bool> fl(32800,false);
    for(auto &nx : s){
      if(nx.size()==2){
        string rs=nx;
        reverse(rs.begin(),rs.end());
        if(fl[to_int(rs)]){isok=true;break;}
        for(char c='a';c<='z';c++){
          rs.push_back(c);
          if(fl[to_int(rs)]){isok=true;break;}
          rs.pop_back();
        }
        if(isok){break;}
      }
      else{
        string rs=nx;
        reverse(rs.begin(),rs.end());
        if(fl[to_int(rs)]){isok=true;break;}
        rs.pop_back();
        if(fl[to_int(rs)]){isok=true;break;}
      }
      fl[to_int(nx)]=true;
    }
    if(isok){cout << "YES\n";continue;}

    {
      vector<bool> cfl(1100,false);
      unordered_set<int> gl;
      for(auto &nx : s){
        if(nx.size()==3){
          if(gl.find(to_int(nx))!=gl.end()){isok=true;break;}
          if(nx[1]!=nx[2]){continue;}
        }
        for(auto &ny : tlis){
          if(cfl[ny]){
            gl.insert((nx[0]-'a'+1)*32*32+(ny%32)*32+(ny/32));
          }
        }
        if(nx.size()==2){cfl[to_int(nx)]=true;}
      }
    }
    if(isok){cout << "YES\n";continue;}

    for(auto &nx : s){reverse(nx.begin(),nx.end());}
    reverse(s.begin(),s.end());
    {
      vector<bool> cfl(1100,false);
      unordered_set<int> gl;
      for(auto &nx : s){
        if(nx.size()==3){
          if(gl.find(to_int(nx))!=gl.end()){isok=true;break;}
          if(nx[1]!=nx[2]){continue;}
        }
        for(auto &ny : tlis){
          if(cfl[ny]){
            gl.insert((nx[0]-'a'+1)*32*32+(ny%32)*32+(ny/32));
          }
        }
        if(nx.size()==2){cfl[to_int(nx)]=true;}
      }
    }
    if(isok){cout << "YES\n";continue;}

    cout << "NO\n";
  }
  return 0;
}
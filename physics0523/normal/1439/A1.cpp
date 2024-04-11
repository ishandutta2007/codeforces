#include<bits/stdc++.h>

using namespace std;

void resout(vector<pair<int,int>> &vc){
  cout << (vc.size()/3) << '\n';
  int mem=0;
  for(auto &nx : vc){
    cout << nx.first+1 << ' ' << nx.second+1;
    mem++;
    if(mem%3==0){cout << '\n';}
    else{cout << ' ';}
  }
}

char rev(char c){
  if(c=='1'){return '0';}
  return '1';
}

void query(vector<pair<int,int>> &ptr,vector<string> &st,vector<pair<int,int>> &res){
  for(auto &nx : ptr){
    st[nx.first][nx.second]=rev(st[nx.first][nx.second]);
    res.emplace_back(nx);
  }
}

void split(vector<pair<int,int>> &s0,vector<pair<int,int>> &s1,vector<string> &st){
  if(st[0][0]=='0'){s0.emplace_back(make_pair(0,0));}else{s1.emplace_back(make_pair(0,0));}
  if(st[0][1]=='0'){s0.emplace_back(make_pair(0,1));}else{s1.emplace_back(make_pair(0,1));}
  if(st[1][0]=='0'){s0.emplace_back(make_pair(1,0));}else{s1.emplace_back(make_pair(1,0));}
  if(st[1][1]=='0'){s0.emplace_back(make_pair(1,1));}else{s1.emplace_back(make_pair(1,1));}
}

void final(vector<string> &st,vector<pair<int,int>> &res){
  while(1){
    vector<pair<int,int>> s0,s1,cq;
    split(s0,s1,st);
    //cerr << s1.size() << '\n';
    if(s1.size()==0){break;}
    else if(s1.size()==1 || s1.size()==2){
      cq.emplace_back(s1[0]);
      cq.emplace_back(s0[0]);
      cq.emplace_back(s0[1]);
    }
    else if(s1.size()==3){cq=s1;}
    else if(s1.size()==4){
      s1.pop_back();
      cq=s1;
    }
    query(cq,st,res);
  }
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
    int rn=n;
    vector<string> s(n);
    vector<pair<int,int>> res;
    for(int i=0;i<n;i++){cin >> s[i];}
    while(n>2){
      for(int i=0;i<(m-1);i++){
        vector<pair<int,int>> cq;
        cq.push_back(make_pair(n-2,i));
        cq.push_back(make_pair(n-2,i+1));
        if(s[n-1][i]=='0' && s[n-1][i+1]=='0'){continue;}
        else if(s[n-1][i]=='0' && s[n-1][i+1]=='1'){
          cq.push_back(make_pair(n-1,i+1));
        }
        else if(s[n-1][i]=='1' && s[n-1][i+1]=='0'){
          cq.push_back(make_pair(n-1,i));
        }
        else{
          cq.pop_back();
          cq.push_back(make_pair(n-1,i));
          cq.push_back(make_pair(n-1,i+1));
        }
        query(cq,s,res);
      }
      n--;
    }
    while(m>2){
      for(int i=0;i<n-1;i++){
        vector<pair<int,int>> cq;
        cq.push_back(make_pair(i,m-2));
        cq.push_back(make_pair(i+1,m-2));
        if(s[i][m-1]=='0' && s[i+1][m-1]=='0'){continue;}
        else if(s[i][m-1]=='0' && s[i+1][m-1]=='1'){
          cq.push_back(make_pair(i+1,m-1));
        }
        else if(s[i][m-1]=='1' && s[i+1][m-1]=='0'){
          cq.push_back(make_pair(i,m-1));
        }
        else{
          cq.pop_back();
          cq.push_back(make_pair(i,m-1));
          cq.push_back(make_pair(i+1,m-1));
        }
        query(cq,s,res);
      }
      m--;
    }
    //cerr << "ok\n";
    final(s,res);
    //for(int i=0;i<rn;i++){cout << s[i] << '\n';}
    resout(res);
  }
}
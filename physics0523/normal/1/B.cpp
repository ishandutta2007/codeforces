#include<bits/stdc++.h>

using namespace std;

int type(char c){
  if('0'<=c && c<='9'){return 1;}
  if('A'<=c && c<='Z'){return 2;}
  return 0;
}

vector<string> read(string s){
  int l=s.size();
  s=s+"A";
  string cur;
  vector<string> res;
  for(int i=0;i<l;i++){
    cur.push_back(s[i]);
    if(type(s[i])!=type(s[i+1])){
      res.push_back(cur);
      cur.clear();
    }
  }
  return res;
}

int str_num(string s){
  int l=s.size();
  int res=0,k=26;
  for(int i=1;i<l;i++){res+=k;k*=26;}
  k=0;
  for(int i=0;i<l;i++){
    k*=26;
    k+=(s[i]-'A');
  }
  return res+k+1;
}

string num_str(int x){
  x--;
  int ul=26;
  for(int i=1;;i++){
    if(x<ul){
      string res;
      for(int j=0;j<i;j++){
        res.push_back('A'+(x%26));
        x/=26;
      }
      reverse(res.begin(),res.end());
      return res;
    }
    x-=ul;
    ul*=26;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    vector<string> dt=read(s);
    if(dt.size()==4){
      cout << num_str(stoi(dt[3]));
      cout << dt[1] << '\n';
    }
    else{
      cout << "R" << dt[1];
      cout << "C" << str_num(dt[0]);
      cout << '\n';
    }
    //cout << dt.size() << '\n';
  }
  return 0;
}
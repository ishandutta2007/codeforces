#include<bits/stdc++.h>

using namespace std;

vector<int> div(int x){
  vector<int> res;
  for(int i=1;i*i<=x;i++){
    if(x%i==0){
      res.push_back(i);
      if(i*i!=x){res.push_back(x/i);}
    }
  }
  return res;
}

map<int,int> mem;

int solve(int x){
  if(x==1){return -1;}
  else if(x%2==1){return 1;}
  if(mem[x]!=0){return mem[x];}
  mem[x]=-1;
  if(solve(x-1)==-1){mem[x]=1;}
  vector<int> dv=div(x);
  for(auto &nx : dv){
    if(mem[x]==1){break;}
    if(nx%2==1 && nx>1){
      if(solve(x/nx)==-1){mem[x]=1;}
    }
  }
  return mem[x];
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
    if(solve(n)==-1){
      cout << "FastestFinger\n";
    }
    else{
      cout << "Ashishgup\n";
    }
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

vector<int> a;
int n,q;

string solve(int te){
  int cq=q;
  string res;
  for(int i=0;i<n;i++){
    if(cq==0){res.push_back('0');continue;}

    if(a[i]>cq){
      if(i<te){res.push_back('0');}
      else{
        cq--;
        res.push_back('1');
      }
    }
    else{
      res.push_back('1');
    }
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
    cin >> n >> q;
    a.resize(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    int st=0,fi=n;
    while(st<=fi){
      int te=(st+fi)/2;
      if(solve(te)[n-1]=='0'){st=te+1;}
      else{fi=te-1;}
    }
    cout << solve(st) << '\n';
  }
  return 0;
}
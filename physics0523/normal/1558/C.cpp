#include<bits/stdc++.h>

using namespace std;

vector<int> res;
void ope(int x,vector<int> &a){
  res.push_back(x+1);
  for(int i=0;i<x;i++){
    int j=x-i;
    if(i>=j){break;}
    swap(a[i],a[j]);
  }
  // for(auto &nx : a){
  //   cerr << nx << ' ';
  // }cerr << '\n';
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
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}

    bool iserr=false;
    for(int i=0;i<n;i++){
      if(i%2==p[i]%2){iserr=true;}
    }
    if(iserr){
      cout << "-1\n";
      continue;
    }

    res.clear();
    for(int i=n;i>=3;i-=2){
      int tg;
      //hand 1
      for(int j=0;j<i;j++){
        if(p[j]==i){tg=j;break;}
      }
      ope(tg,p);

      //hand 2
      for(int j=0;j<i;j++){
        if(p[j]==i-1){tg=j-1;break;}
      }
      ope(tg,p);

      //hand 3
      for(int j=0;j<i;j++){
        if(p[j]==i-1){tg=j+1;break;}
      }
      ope(tg,p);

      //hand 4
      for(int j=0;j<i;j++){
        if(p[j]==i){tg=j;break;}
      }
      ope(tg,p);

      //hand 5
      ope(i-1,p);
    }

    // for(auto &nx : p){
    //   cout << nx << ' ';
    // }cout << '\n';

    cout << res.size() << '\n';
    bool fl=false;
    for(auto &nx : res){
      if(fl){cout << ' ';}
      cout << nx;
      fl=true;
    }cout << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

bool strat1(int te,int d,vector<int> &a){
    int ag=0;
    vector<int> b={0};
    for(auto &nx : a){
      if(nx-b.back()<=te){ag++;}
      else{b.push_back(nx);}
    }
    for(int i=1;i<b.size();i++){
      if(b[i]-b[i-1]<=te){return false;}
    }
    if(ag>1){return false;}
    if(ag==0){return true;}
    if(d-b.back()>te){return true;}
    int wtg=2*(te+1);
    bool isok=false;
    for(int i=1;i<b.size();i++){
      if(b[i]-b[i-1]>=wtg){isok=true;}
    }
    return isok;
}

bool strat2(int te,int d,vector<int> &a){
    int ag=0;
    vector<int> b={0};
    for(auto &nx : a){
      if(nx-b.back()<=te){
        ag++;
        if(b.back()==0){return false;}
        b.pop_back();
      }
      b.push_back(nx);
    }
    for(int i=1;i<b.size();i++){
      if(b[i]-b[i-1]<=te){return false;}
    }
    if(ag>1){return false;}
    if(ag==0){return true;}
    if(d-b.back()>te){return true;}
    int wtg=2*(te+1);
    bool isok=false;
    for(int i=1;i<b.size();i++){
      if(b[i]-b[i-1]>=wtg){isok=true;}
    }
    return isok;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,d;
    cin >> n >> d;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    int st=0,fi=1000000007;
    while(st<=fi){
      int te=(st+fi)/2;
      if(strat1(te,d,a)){st=te+1;continue;}
      if(strat2(te,d,a)){st=te+1;continue;}
      fi=te-1;
    }
    cout << fi << '\n';
  }
  return 0;
}
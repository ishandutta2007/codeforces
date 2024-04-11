#include<bits/stdc++.h>

using namespace std;

int ask(int x){
  cout << "? " << x << '\n';
  fflush(stdout);
  int res;
  cin >> res;
  return res;
}

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> res(n+1,-1);
    vector<bool> fl(n+1,false);
    for(int i=1;i<=n;i++){
      if(res[i]!=-1){continue;}
      vector<int> circ;
      int tg=i;
      while(1){
        int x=ask(tg);
        circ.push_back(x);
        if(fl[x]){break;}
        fl[x]=true;
      }
      for(int i=0;i<circ.size()-1;i++){
        res[circ[i]]=circ[i+1];
      }
    }
    cout << "!";
    for(int i=1;i<=n;i++){
      cout << ' ' << res[i];
    }cout << '\n';
    fflush(stdout);
  }
  return 0;
}
#include<bits/stdc++.h>
#define mod 998244353

using namespace std;
using ps=pair<string,string>;

int n;
string s;
long long res=1;

string solve(int v,int h){
  string trs;
  if(h!=0){
    string lef=solve(2*v+1,h-1);
    string rig=solve(2*v+2,h-1);
    if(lef>rig){swap(lef,rig);}
    trs=lef+rig;
    if(lef!=rig){res*=2;res%=mod;}
  }

  if(s[v]=='A'){trs="A"+trs;}
  else{trs="B"+trs;}
  return trs;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  cin >> s;
  solve(0,n-1);
  cout << res << '\n';
  return 0;
}
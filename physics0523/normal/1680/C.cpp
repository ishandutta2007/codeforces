#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int l=s.size();
    vector<int> rz(l+1,0),ro(l+1,0);
    for(int i=0;i<l;i++){
      rz[i+1]+=rz[i];
      ro[i+1]+=ro[i];
      if(s[i]=='0'){rz[i+1]++;}else{ro[i+1]++;}
    }
    int res=1e9;
    for(int i=0;i<=l;i++){
     int st=i,fi=l;
     while(st<=fi){
       int te=(st+fi)/2;
       int p0=rz[te]-rz[i];
       int p1=ro[l]-(ro[te]-ro[i]);
       res=min(res,max(p0,p1));
       if(p0<p1){st=te+1;}else{fi=te-1;}
     }
    }
    cout << res << '\n';
  }
  return 0;
}
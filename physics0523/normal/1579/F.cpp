#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;

int circ(vector<int> &a){
  int res=-inf,c=0;
  for(int i=0;i<3*a.size();i++){
    if(a[(i%a.size())]==1){c++;}
    else{
      res=max(c,res);
      c=0;
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
    int n,d;
    cin >> n >> d;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int res=0;
    vector<bool> fl(n,false);
    for(int i=0;i<n;i++){
      if(fl[i]){continue;}
      vector<int> ca;
      int p=i;
      while(!fl[p]){
        //cout << p << ',';
        fl[p]=true;ca.push_back(a[p]);
        p+=d;p%=n;
      }//cout << '\n';
      int cv=circ(ca);
      if(cv==-inf){res=-1;break;}
      res=max(res,cv);
    }
    cout << res << '\n';
  }
  return 0;
}
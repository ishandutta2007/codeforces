#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int res=-1,j=0,cs=0;
    for(int i=0;i<n;i++){
      while(j<n && cs<=s){
        if(cs==s){res=max(res,j-i);}
        cs+=a[j];j++;
      }
      if(cs==s){res=max(res,j-i);}
      cs-=a[i];
    }
    if(res<0){res=n+1;}
    cout << n-res << '\n';
  }
  return 0;
}
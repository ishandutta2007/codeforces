#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin >> a[i][j];
      }
    }
    int res=0;
    for(int i=0;i<2*n;i+=4){
      int p,q;
      if(i<n){p=0;q=i;}
      else{q=n-1;p=i-q;}
      while(q>=0){
        if(0<=p&&p<n&&0<=q&&q<n){res^=a[p][q];}
        p+=2;q-=2;
      }
    }
    for(auto &nx : a){reverse(nx.begin(),nx.end());}
    for(int i=0;i<2*n;i+=4){
      int p,q;
      if(i<n){p=0;q=i;}
      else{q=n-1;p=i-q;}
      while(q>=0){
        if(0<=p&&p<n&&0<=q&&q<n){res^=a[p][q];}
        p+=2;q-=2;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
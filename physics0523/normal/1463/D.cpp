#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;

bool is(long long p,long long st,long long fi){
  if(min(st,fi)<=p && p<=max(st,fi)){return true;}
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n),b(2*n+1,0);
    for(int i=0;i<n;i++){
      cin >> a[i];
      b[a[i]]=1;
    }
    int mi=0,ma=n;
    int st=0;
    for(int i=1;i<=2*n;i++){
      if(b[i]==1){
        if(st>0){st--;}
        else{mi++;}
      }
      else{st++;}
    }
    st=0;
    for(int i=2*n;i>=1;i--){
      if(b[i]==1){
        if(st>0){st--;}
        else{ma--;}
      }
      else{st++;}
    }
    cout << max(0,ma-mi+1) << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> p;
    if(((n-1)/2)<k){cout << "-1\n";continue;}
    int mi=1,ma=n;
    for(int i=0;i<n;i++){
      if(i%2==0){
        p.push_back(mi);mi++;
        if(i!=0){k--;}
        if(k==0){
          while(mi<=ma){p.push_back(mi);mi++;}
          break;
        }
      }
      else{p.push_back(ma);ma--;}
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << p[i];
    }
    cout << '\n';
  }
  return 0;
}
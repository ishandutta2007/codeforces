#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}

    if(n%2){cout << "-1\n";continue;}

    int sig=0;
    for(int i=0;i<n;i++){
      int ce;
      if(i%2==0){ce=1;}
      else{ce=-1;}
      sig+=a[i]*ce;
    }

    vector<pi> vp;
    for(int i=0;i<n;i+=2){
      if(sig>0 && a[i+1]==-1){
        vp.push_back({i,i});
        vp.push_back({i+1,i+1});
        sig-=2;
      }
      else if(sig<0 && a[i+1]==1){
        vp.push_back({i,i});
        vp.push_back({i+1,i+1});
        sig+=2;
      }
      else{
        vp.push_back({i,i+1});
      }
    }

    cout << vp.size() << "\n";
    for(auto &nx : vp){
      cout << nx.first+1 << " " << nx.second+1 << "\n";
    }
  }
  return 0;
}
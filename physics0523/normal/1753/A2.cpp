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

    int ab=0;
    int sig=0;
    int ce=1;
    for(int i=0;i<n;i++){
      if(a[i]==0){continue;}
      sig+=a[i]*ce;
      ce*=-1;
      ab+=max(a[i],-a[i]);
    }
    if(ab%2){cout << "-1\n";continue;}

    vector<int> wall(n+1,0);
    vector<pi> vp;
    int i=0;
    ce=1;
    while(i<n){

      if(a[i]==0){
        wall[i]=1;
        i++;
        continue;
      }

      if(ce==1){
        wall[i]=1;
      }
      else{
        if(sig>0 && a[i]==-1){
          wall[i]=1;
          sig-=2;
        }
        else if(sig<0 && a[i]==1){
          wall[i]=1;
          sig+=2;
        }
      }
      i++;
      ce*=-1;
    }

    wall[n]=1;
    int lef=0;
    for(i=1;i<=n;i++){
      if(wall[i]==1){
        vp.push_back({lef,i-1});
        lef=i;
      }
    }
    cout << vp.size() << "\n";
    for(auto &nx : vp){
      cout << nx.first+1 << " " << nx.second+1 << "\n";
    }
  }
  return 0;
}
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
    int ev=(n*k)/2;
    int od=ev+(n*k)%2;
    if(ev%k!=0 || od%k!=0){cout << "NO\n";continue;}
    cout << "YES\n";
    int id=1;
    for(int i=0;i<n;i++){
      for(int j=0;j<k;j++){
        if(j){cout << ' ';}
        cout << id;
        id+=2;
        if(id>n*k){id=2;}
      }cout << '\n';
    }
  }
  return 0;
}
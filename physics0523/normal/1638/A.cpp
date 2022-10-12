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
    vector<int> p(n);
    int aim=1e9;
    for(int i=0;i<n;i++){
      cin >> p[i];
      if((i+1)!=p[i]){aim=min(aim,i+1);}
    }
    if(aim<5e8){
      int x=aim-1,y;
      for(int i=0;i<n;i++){
        if(p[i]==aim){y=i;}
      }
      while(x<y){swap(p[x],p[y]);x++;y--;}
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << p[i];
    }cout << '\n';
  }
  return 0;
}
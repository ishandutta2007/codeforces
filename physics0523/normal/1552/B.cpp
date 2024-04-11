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
    vector<vector<int>> a(n,vector<int>(5));

    for(int i=0;i<n;i++){
      for(int j=0;j<5;j++){
        cin >> a[i][j];
      }
    }

    if(n==1){cout << "1\n";continue;}

    int rk=0;
    for(int i=1;i<n;i++){
      int dp=0,cp=0;
      for(int j=0;j<5;j++){
        if(a[rk][j]<a[i][j]){dp++;}
        else if(a[rk][j]>a[i][j]){cp++;}
      }
      if(dp<cp){rk=i;}
    }

    for(int i=0;i<n;i++){
      if(i==rk){continue;}
      int dp=0;
      for(int j=0;j<5;j++){
        if(a[rk][j]<a[i][j]){dp++;}
      }
      if(dp<3){rk=-2;}
      if(rk==-2){break;}
    }
    rk++;
    cout << rk << '\n';
  }
  return 0;
}
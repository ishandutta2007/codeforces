#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,c;
    cin >> n >> c;
    vector<int> a(n);
    vector<int> bk(3*c+5,0);
    for(auto &nx : a){
      cin >> nx;
      bk[nx]++;
    }
    vector<int> bm=bk;

    for(int i=1;i<3*c+5;i++){bk[i]+=bk[i-1];}
    sort(a.begin(),a.end());
    a.push_back(-1);

    bool isok=true;
    for(int i=0;i<n;i++){
      if(a[i]==a[i+1]){continue;}
      for(int j=1;;j++){
        int l=(a[i]*j);l--;
        int r=(a[i]*(j+1));r--;
        if(c<l){break;}
        if((bk[r]-bk[l])>0){
          if(bm[j]==0){isok=false;break;}
        }
      }
      if(!isok){break;}
    }

    if(isok){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}
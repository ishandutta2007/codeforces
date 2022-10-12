#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    int l=s.size();
    vector<int> rw(l+1,0);
    for(int i=1;i<=l;i++){
      rw[i]=rw[i-1]+(s[i-1]-'0');
    }
    int w,m;
    cin >> w >> m;
    vector<long long> bk(9);
    vector<vector<int>> mem(9);
    for(int i=w;i<=l;i++){
      bk[(rw[i]-rw[i-w])%9]++;
      mem[(rw[i]-rw[i-w])%9].push_back(i-w+1);
    }
    for(int tr=0;tr<m;tr++){
      int l,r,k;
      cin >> l >> r >> k;
      l=(rw[r]-rw[l-1])%9;
      vector<int> res={1000000000,1000000000};
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          if((i*l+j)%9==k){
            if(i!=j){
              if(bk[i]>0 && bk[j]>0){res=min(res,{mem[i][0],mem[j][0]});}
            }
            else{
              if(bk[i]>1){res=min(res,{mem[i][0],mem[i][1]});}
            }
          }
        }
      }
      if(res[0]>5e8){res[0]=-1;res[1]=-1;}
      cout << res[0] << " " << res[1] << "\n";
    }
  }
  return 0;
}
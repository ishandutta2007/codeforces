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
    int n,q;
    cin >> n >> q;

    vector<vector<int>> bk(n+1);
    vector<int> cur(30,0);
    vector<vector<int>> pts(30);

    bk[0]=cur;
    for(int i=1;i<=n;i++){
      int a;
      cin >> a;
      for(int j=0;j<30;j++){
        if(a&(1<<j)){
          cur[j]++;
          pts[j].push_back(i);
        }
      }
      bk[i]=cur;
    }

    for(int i=0;i<q;i++){
      int l,r;
      cin >> l >> r;
      vector<pi> iv,ov;
      int segc=0;
      vector<int> mem(30,0);

      for(int j=0;j<30;j++){
        int cnt=bk[r][j]-bk[l-1][j];
        if(cnt<=1){
          segc++;
        }
        else if(cnt%2==0){
          iv.push_back({pts[j][bk[r][j]-1],j});
          ov.push_back({pts[j][bk[l-1][j]],j});
        }
        else{
          iv.push_back({pts[j][bk[r][j]-2],j});
          ov.push_back({pts[j][bk[l-1][j]],j});

          iv.push_back({pts[j][bk[r][j]-1],j});
          ov.push_back({pts[j][bk[l-1][j]+1],j});
        }
      }

      sort(iv.begin(),iv.end());
      reverse(iv.begin(),iv.end());
      sort(ov.begin(),ov.end());
      reverse(ov.begin(),ov.end());

      // for(auto &nx : iv){cerr << nx.first << "," << nx.second << "\n";}
      // for(auto &nx : ov){cerr << nx.first << ":" << nx.second << "\n";}

      if(iv.empty()){
        cout << l << " " << l << "\n";
        continue;
      }

      int rl=-1e9,rr=1e9;
      int cl=ov.back().first-1,cr=l;
      // cerr << l << "," << r << "\n";
      // cerr << cl << " " << cr << "\n";

      while(1){
        // cerr << cl << " " << cr << "\n";
        if(segc<30){
          if(iv.empty()){break;}

          cr=iv.back().first;
          if(mem[iv.back().second]==0){segc++;}
          mem[iv.back().second]++;
          iv.pop_back();
        }
        else{
          if(rr-rl > cr-cl){rl=cl;rr=cr;}
          if(ov.empty()){break;}

          mem[ov.back().second]--;
          if(mem[ov.back().second]==0){segc--;}
          ov.pop_back();

          if(ov.empty()){cl=r-1;}
          else{cl=min(r-1,ov.back().first-1);}
        }
      }

      if(rl+1 > rr){cout << l << " " << l << "\n";}
      else{cout << rl+1 << " " << rr << "\n";}
    }
  }
  return 0;
}
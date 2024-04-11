#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int ha[1048576];
  for(int i=1;i<=1048576;i++){
    int c=i,v=1;
    for(int j=2;j*j<=c;j++){
      if((c%j)!=0){continue;}
      int pc=0;
      while((c%j)==0){
        pc++;
        c/=j;
      }
      if(pc%2==1){v*=j;}
    }
    v*=c;
    ha[i]=v;
  }
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> um;
    for(int i=0;i<n;i++){
      cin >> a[i];
      um[ha[a[i]]]++;
    }
    vector<int> res(3);
    res[0]=um[1];
    res[1]=um[1];
    for(int i=0;i<n;i++){
      int cc=um[ha[a[i]]];
      //cout << cc << ">\n";
      res[0]=max(cc,res[0]);
      if(cc%2==0 && ha[a[i]]!=1){
        res[1]+=cc;
      }
      um[ha[a[i]]]=0;
    }
    res[0]=max(1,res[0]);
    res[1]=max(res[0],res[1]);
    int q;
    cin >> q;
    while(q>0){
      q--;
      long long w;
      cin >> w;
      if(w>1){w=1;}
      cout << res[w] << '\n';
    }
  }
  return 0;
}
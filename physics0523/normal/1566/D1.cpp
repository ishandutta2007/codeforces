#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<bitset<320>> v(n);
    vector<int> a(n*m),b(n*m);

    for(int i=0;i<n*m;i++){
      cin >> a[i];
      b[i]=a[i];
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<320;j++){v[i].reset(j);}
    }

    sort(b.begin(),b.end());
    unordered_map<int,vector<int>> cd;
    for(int i=0;i<n*m;i++){
      if((i%m)!=(m-1) && b[i]==b[i+1]){continue;}
      cd[b[i]].push_back(i);
    }
    set<int> bomb;
    for(int i=0;i<n;i++){bomb.insert(i*m);}
    for(int i=1;i<n*m;i++){
      if(b[i-1]!=b[i]){bomb.insert(i);}
    }

    int res=0;
    for(int i=0;i<n*m;i++){
      int dp=-1,del=1000000007,ap;
      for(int j=0;j<cd[a[i]].size();j++){
        int ord=cd[a[i]][j],p,tg;
        //cout << ord << ',';
        p=ord/m;
        tg=ord%m;

        int dv=(m-tg)-((v[p]>>tg).count());
        dv--;
        if(del>dv){dp=ord;del=dv;ap=j;}
        if(del==0){break;}
      }
      res+=del;
      int p=dp/m,q=dp%m;
      //cout << p << ' ' << q << '\n';
      v[p].set(q);
      if(bomb.find(cd[a[i]][ap])!=bomb.end()){
        cd[a[i]][ap]=cd[a[i]].back();
        cd[a[i]].pop_back();
      }
      else{cd[a[i]][ap]--;}
    }
    cout << res << '\n';
  }
  return 0;
}
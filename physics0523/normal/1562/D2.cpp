#include<bits/stdc++.h>

using namespace std;

int enhance(int x){
  if(x>0){x++;}else{x--;}
  return x;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> rw(n+1,0);
    vector<int> pl,mn;
    map<int,set<int>> mp;

    for(int i=0;i<n;i++){
      rw[i+1]=rw[i];
      if(i%2==0){s[i]='+'+'-'-s[i];}
      if(s[i]=='+'){rw[i+1]++;pl.push_back(i);}
      else{rw[i+1]--;mn.push_back(i);}
    }

    for(int i=0;i<=n;i++){mp[rw[i]].insert(i);}

    while(q>0){
      q--;
      int l,r;
      cin >> l >> r;
      int val=abs(rw[r]-rw[l-1]);
      if(val==0){cout << 0 << '\n';}
      else{
        vector<int> res;
        if(val%2==0){
          res.push_back(r);
          r--;
        }
        int tg=rw[l-1]+enhance(rw[r]-rw[l-1])/2;
        res.push_back(*mp[tg].lower_bound(l));

        cout << res.size() << '\n';
        for(int i=0;i<res.size();i++){
          if(i){cout << ' ';}
          cout << res[i];
        }cout << '\n';
      }
    }
  }
  return 0;
}
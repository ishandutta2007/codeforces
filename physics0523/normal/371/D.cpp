#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> cur(n+1,0);
  vector<long long> cap(n);
  for(auto &nx : cap){cin >> nx;}
  cap.push_back(8e18);
  set<long long> st;
  for(int i=0;i<=n;i++){st.insert(i);}

  int q;
  cin >> q;
  while(q>0){
    q--;
    int t;
    cin >> t;
    if(t==1){
      long long p,x;
      cin >> p >> x;
      //cout << p << ',' << x << '\n';
      p--;

      p=(*st.lower_bound(p));
      while(x>0){
        long long merg=cap[p]-cur[p];
        merg=min(merg,x);
        x-=merg;
        cur[p]+=merg;
        if(cur[p]==cap[p]){st.erase(p);}
        if(x>0){p=(*st.lower_bound(p));}
      }
    }
    else{
      long long p;
      cin >> p;
      p--;
      cout << cur[p] << '\n';
    }
  }
  return 0;
}
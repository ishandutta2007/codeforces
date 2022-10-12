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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}

    int res=0;
    for(int bas=0;bas<n;bas++){
      vector<int> dp(n+1,-1e9);
      dp[bas]=0;
      for(int i=bas;i<n;i++){
        set<int> st;
        for(int i=0;i<=n;i++){st.insert(i);}
        for(int j=i;j>=0;j--){
          if(st.find(a[j])!=st.end()){st.erase(a[j]);}
          dp[i+1]=max(dp[i+1],dp[j]+1+(*st.begin()));
        }
      }
      for(int i=bas+1;i<=n;i++){res+=dp[i];}
    }
    cout << res << '\n';
  }
  return 0;
}
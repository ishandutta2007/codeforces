#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, x, y, ans;
  ans=0;
  cin >> n >> m;

  int a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  pair<pair<int, int>, pair<int, int> > q[m]; // start / 400 , end, start
  for(int i=0; i<m; i++){
    cin >> x >> y;
    q[i]=make_pair(make_pair((x-1)/300, y-1), make_pair(i, x - 1));
  }

  sort(q, q + m);

  int l=0;
  int r=-1;
  unordered_map<int, int> mp;
  int an[m];

  for(int i=0; i<m; i++){
    while(q[i].first.second > r){
      r++;
      if(mp[a[r]] == a[r]) ans--;
      mp[a[r]]++;
      if(mp[a[r]] == a[r]) ans++;
    }

    while(q[i].first.second < r){
      if(mp[a[r]] == a[r]) ans--;
      mp[a[r]]--;
      if(mp[a[r]] == a[r]) ans++;
      r--;
    }

    while(q[i].second.second > l){
      if(mp[a[l]] == a[l]) ans--;
      mp[a[l]]--;
      if(mp[a[l]] == a[l]) ans++;
      l++;
    }

    while(q[i].second.second < l){
      l--;
      if(mp[a[l]] == a[l]) ans--;
      mp[a[l]]++;
      if(mp[a[l]] == a[l]) ans++;
    }

    an[q[i].second.first]=ans;    
  }

  for(int i=0; i<m; i++){
    cout << an[i] << endl;
  }
}
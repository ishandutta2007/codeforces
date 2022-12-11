#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main(){
  int n,k;
  ll x;
  cin >> n >> k >> x;
  int sign = 0;
  ll el[n];
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>sk;
  for(int j = 0;j<n;j++){
    cin >> el[j];
    if(el[j]<0)sign++;
    sk.push(mp(abs(el[j]),j));
  }
  int j;
  while(k--){
    j = sk.top().se;
    sk.pop();
    if(sign%2==1){
      if(el[j]<0)el[j]-=x;
      else el[j]+=x;
    }
    else{
      if(el[j]>=0){
        el[j]-=x;
        if(el[j]<0)sign++;
      }
      else{
        el[j]+=x;
        if(el[j]>=0)sign++;
      }
    }
    sk.push(mp(abs(el[j]),j));
  }
  for(int i = 0;i<n;i++)cout << el[i] << " ";
  return 0;
}
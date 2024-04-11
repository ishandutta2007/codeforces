#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main(){
  int n;
  ll d;
  cin >> n >> d;
  ll a,b;
  cin >> a >> b;
  pair<ll,int>client[n];
  ll low,high;
  for(int i = 1;i<=n;i++){
    cin >> low >> high;
    client[i-1]=mp((low*a)+(high*b),i);
  }
  sort(client,client+n);
  vector<int>ans; 
  for(int i = 0;i<n;i++){
    if(client[i].fi<=d){
      d-=client[i].fi;
      ans.push_back(client[i].se);
    }
  }
  cout << ans.size() << "\n";
  for(auto x : ans)
    cout << x << " ";
  cout << "\n";

  return 0;
}
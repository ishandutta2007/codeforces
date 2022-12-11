#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e7 + 10;
bool isnt[N];
int l1[N], l2[N];

int main(){
  fastIO;
  for(int i = 2; i < N ; i ++ ){
    if(!isnt[i]){
      for(int j = i ; j < N ; j += i){
        if(l1[j] == 0){
          l1[j]=i;
        }
        else{
          l2[j]=max(l2[j],1);
          l2[j] *= i;
        }
        isnt[j]=true;
      }
    }
  }
  int n;
  cin >> n;
  vector<pii> ans;
  int x;
  for(int i = 0 ; i <n; i ++ ){
    cin >> x;
    if(l1[x] == 0 || l2[x] == 0)
      ans.push_back(mp(-1,-1));
    else
      ans.push_back(mp(l1[x], l2[x]));
  }
  for(auto x : ans){
    cout << x.fi << " ";
  }
  cout << "\n";
  for(auto x : ans){
    cout << x.se << " ";
  }
  cout << "\n";
  return 0;
}
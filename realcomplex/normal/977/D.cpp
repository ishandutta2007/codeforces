#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 105;
vector<int>T[N];
bool V[N];
vector<int>order;
ll seq[N];

void top_sort(int x){
  if(V[x])
    return;
  V[x] = true;
  for(auto y : T[x])
    top_sort(y);
  order.push_back(x);
}

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1;i <= n;i ++ ){
    cin >> seq[i];
  }
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1;j <= n;j ++ ){
      if(i == j)
        continue;
      if(seq[i] * 2 == seq[j]){
        T[i].push_back(j);
      }
      else{
        if(seq[i] % 3 == 0)
          if(seq[i] / 3 == seq[j])
            T[i].push_back(j);
      }
    }
  }
  for(int i = 1;i <= n;i++)
    top_sort(i);
  reverse(order.begin(),order.end());
  for(auto x : order)
    cout << seq[x] << " ";
  return 0;
}
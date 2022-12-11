#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)2e5 + 12345;
int be[N];
int len[N];

int main(){
  fastIO;
  int n,w,k;
  cin >> n >> w >> k;
  for(int i = 1;i<=n;i++){
    cin >> be[i];
  }
  for(int i = 1;i<=n;i++){
    cin >> len[i];
  }
  int p = 0;
  int total_length = 0;
  int current = 0,ans = 0;
  multiset<int>partly,not_part;
  for(int i = 1;i<=n;i++){
    partly.insert(len[i]);
    current += be[i];
    total_length += (len[i] + 1)/2;
    if(partly.size() > w){
      auto x = partly.begin();
      total_length += (*x)/2;
      not_part.insert((*x));
      partly.erase(x);
    }
    while(total_length > k and p <= i){
      p++;
      current -= be[p];
      if(partly.count(len[p]) >= 1){
        total_length -= (len[p]+1)/2;
        partly.erase(partly.find(len[p]));
        if(!not_part.empty()){
          auto x = not_part.end();
          --x;
          total_length -= (*x) / 2;
          partly.insert(*x);
          not_part.erase(x);
        }
      }
      else{
        total_length -= len[p];
        not_part.erase(not_part.find(len[p]));
      }
    }
    ans = max(ans,current);
  }
  cout << ans << "\n";
  return 0;
}
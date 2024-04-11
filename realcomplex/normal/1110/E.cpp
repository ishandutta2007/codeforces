#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int a[N];
int b[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i ++ )
    cin >> b[i];
  multiset<int> shit;
  for(int i = 1 ; i < n; i ++ ){
    shit.insert(a[i] - a[i + 1]);
  }
  for(int i = 1; i < n ; i ++ ){
    if(shit.count(b[i]-b[i+1]))shit.erase(shit.find(b[i] - b[i+1]));
  }
  if(a[1] == b[1] && a[n] == b[n] && shit.empty())
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
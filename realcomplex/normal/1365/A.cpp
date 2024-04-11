#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 55;
bool l[N],r[N];

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    // wtf is this shit
    int n, m;
    cin >> n >> m;
    int x;
    for(int i = 1; i <= n; i ++ ){
      l[i]=false;
    }
    for(int i = 1; i <= m ; i ++ ){
      r[i]=false;
    }
    for(int i = 1; i <= n; i ++ ){
      for(int j = 1; j <= m ; j ++ ){
        cin >> x;
        if(x)
          l[i]=true,r[j]=true;
      }
    }
    int l0 = 0, l1 = 0;
    for(int i = 1; i <= n; i ++ ){
      if(!l[i]) l0 ++ ;
    }
    for(int j = 1; j <= m ; j ++ ){
      if(!r[j]) l1 ++ ;
    }
    l0 = min(l0,l1);
    if(l0 % 2 == 1)
      cout << "Ashish\n";
    else
      cout << "Vivek\n";
  }
  return 0;
}
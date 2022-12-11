#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

void Output(int L,int R){
  for(int i = L + 1; i <= R;i ++ ){
    cout << i << " ";
  }
  cout << L << " ";
}

int main(){
  fastIO;
  int n,a,b;
  cin >> n >> a >> b;
  int y;
  for(int x = 0;x * a <= n; x ++ ){
    y = n - (x * a);
    if(y % b != 0)
      continue;
    y /= b;
    int P = 1;
    for(int i = 0;i < x;i ++ ){
      Output(P,P + a - 1);
      P += a;
    }
    for(int i = 0;i < y; i ++ ){
      Output(P, P + b - 1);
      P += b;
    }
    cout << "\n";
    return 0;
  }
  cout << "-1\n";
  return 0;
}
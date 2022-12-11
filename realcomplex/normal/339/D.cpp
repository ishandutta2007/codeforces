#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()

const int N = (1 << 17) + 9;
int tree[N * 2];

int main(){
  fastIO;
  int n,q;
  cin >> n >> q;
  n = (1 << n);
  int ax;
  int p;
  int cnt = 0;
  for(int i = 0;i < n;i ++ ){
    cin >> ax;
    p = i + n;
    tree[p] = ax;
    p /= 2;
    cnt = 0;
    while(p > 0){
      if(cnt & 1){
        tree[p] = tree[p * 2] ^ tree[p * 2 + 1];
      }
      else{
        tree[p] = tree[p * 2] | tree[p * 2 + 1];
      }
      cnt ++ ;
      p /= 2;
    }
  }
  int x,b;
  for(int i = 0;i < q;i ++ ){
    cin >> x >> b;
    x -- ;
    x += n;
    tree[x] = b;
    x /= 2;
    cnt = 0;
    while(x > 0){
      if(cnt & 1){
        tree[x] = tree[x * 2] ^ tree[x * 2 + 1];
      }
      else{
        tree[x] = tree[x * 2] | tree[x * 2 + 1];
      }
      cnt ++ ;
      x /= 2;
    } 
    cout << tree[1] << "\n";
  }
  return 0;
}
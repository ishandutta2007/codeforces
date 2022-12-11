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

const int N = 1009;
int cnt[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  char k;
  for(int i = 1;i <= n;i ++ ){
    cin >> k;
    if(k == '1')
      cnt[i] = 1;
    else
      cnt[i] = 0;
  }
  for(int i = 2;i <= n;i ++ )
    if(cnt[i] == 1 and cnt[i - 1] == 1){
      cout << "No\n";
      return 0;
    }
  for(int i = 2;i <= n+1;i ++){
    if(cnt[i] + cnt[i - 1] + cnt[i - 2] == 0){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
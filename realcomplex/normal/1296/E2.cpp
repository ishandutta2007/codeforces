#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
const int K = 30;
int d[K];
int res[N];

int main(){
  fastIO;
  for(int i = 0 ; i < K; i ++ )
    d[i] = -1;
  int n;
  cin >> n;
  char f;
  int id;
  int pp = 0;
  for(int i = 1; i <= n; i ++ ){
    cin >> f;
    id = f - 'a';
    int bes = 0;
    for(int j = 1 ; j < K ; j ++ )
      if(d[j] <= id && d[j] > d[bes])
        bes=j;
    if(bes == 0){
      pp ++ ;
      d[pp] = id;
      res[i] = pp;
    }
    else{
      d[bes] = id;
      res[i] = bes;
    }
  }
  cout << pp << "\n";
  for(int i = 1; i <= n; i ++ )
    cout << res[i] << " ";
  return 0; 
}
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

const int N=  (int)109;
char conf[N];

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  for(int i = 1;i<=n;i++){
    cin >> conf[i];
  }
  int p = 0;
  for(int i = 1;i<=n;i++){
    if(conf[i] == 'G' or conf[i] == 'T'){
      p = i;
      break;
    }
  }
  p+=k;
  while(conf[p] != 'T' and conf[p] != 'G'){
    if(conf[p] != '.'){
       cout << "NO\n";
       return 0;
    }
    p+=k;
  }
  cout << "YES\n";
  return 0;
}
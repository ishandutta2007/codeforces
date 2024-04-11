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

int main(){
  fastIO;
  int n,m,k;
  cin >> n >> m >> k;
  int l = m * 2;
  int r = (k-1)/l;
  int v = k % l;
  r++;
  cout << r << " ";
  cout << (v == 0 ? l/2 : (v + 1) / 2) << " ";
  cout << (v%2 == 1 ? 'L' : 'R'); 
  return 0;
}
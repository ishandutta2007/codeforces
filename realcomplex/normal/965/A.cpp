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

int main(){
  fastIO;
  int k,n,s,p;
  cin >> k >> n >> s >> p;
  int R = (n + s - 1) / s;
  R *= k;
  R = (R + p - 1) / p;
  cout << R;
  return 0;
}
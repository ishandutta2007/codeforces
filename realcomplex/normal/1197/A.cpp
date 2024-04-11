#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
 fastIO; 
 int testc;
 cin >> testc;
 for(int tt = 0;tt <testc;tt++){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0 ; i < n; i ++ ){
   cin >>a[i];
  }
  sort(a,a+n);
  cout << min(n-2,a[n-2]-1) << "\n";
 }
 return 0;
}
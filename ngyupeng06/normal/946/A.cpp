#include <bits/stdc++.h>

using namespace std;

typedef long long int li;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back

li n, a, b, sum;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> a;
    if (a>0) sum+=a;
    else sum-=a;
  }
  cout << sum;
}
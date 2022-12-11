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
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n,K;
  cin >> n >> K;
  int a[n];
  for(int i = 0;i < n;i ++ )
    cin >> a[i];
  sort(a, a + n);
  int ans = n;
  int eat = 0;
  int common = 1;
  for(int i = 1;i < n;i ++ ){
    if(a[i] > a[i - 1] and a[i] <= a[i - 1] + K){
      eat += common;
    }
    if(a[i] == a[i - 1]){
      common ++ ;
    }
    else{
      common = 1;
    }
  }
  cout << n-eat << "\n";
  return 0;
}
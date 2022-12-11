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
  string s;
  cin >> s;
  int n = s.size();
  int A, B, C;
  for(int i = 2;i < n;i ++ ){
    A = 0, B = 0, C = 0;
    if(s[i] == 'A')
      A ++ ;
    else if(s[i] == 'B')
      B ++ ;
    else if(s[i] == 'C')
      C ++ ;
    if(s[i-1] == 'A')
      A ++ ;
    else if(s[i-1] == 'B')
      B ++ ;
    else if(s[i - 1] == 'C')
      C ++ ;
    if(s[i-2] == 'A')
      A ++ ;
    else if(s[i-2] == 'B')
      B ++ ;
    else if(s[i - 2] == 'C')
      C ++ ;
    if(A == 1 and B == 1 and C == 1){
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
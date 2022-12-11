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
  int n,p;
  cin >> n >> p;
  string s;
  cin >> s;
  for(int i = 0;i < n-p;i ++){
    if(s[i] == '.'){
      if(s[i + p] == '1')
        s[i] = '0';
      else
        s[i] = '1';
      for(int i = 0;i < n;i ++ )
        if(s[i] == '.')
          s[i] = '0';
      cout << s << "\n";
      return 0;
    }
    if(s[i + p] == '.'){
      if(s[i] == '1')
        s[i+p] = '0';
      else
        s[i+p] = '1';
      for(int i = 0;i < n;i ++ )
        if(s[i] == '.')
          s[i] = '0';
      cout << s << "\n";
      return 0;
    }
    if(s[i] != s[i + p]){
      for(int i = 0;i < n;i ++ ){
        if(s[i] == '.')
          s[i] = '0';
      }
      cout << s << "\n";
      return 0;
    }
  } 
  cout << "No\n";
  return 0;
}
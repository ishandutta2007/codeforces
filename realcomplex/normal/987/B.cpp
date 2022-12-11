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
  int x,y;
  cin >> x >> y;
  if(x == y)
    cout << "=";
  else if(x == 1)
    cout << "<";
  else if(y == 1)
    cout << ">";
  else if(x + y == 6)
    cout << "=";
  else if(x == 3)
    cout << ">";
  else if(y == 3)
    cout << "<";
  else if(x < y)  
    cout << ">";
  else
    cout << "<";
  return 0;
}
#pragma optimize ("O3")
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


int in;
int out;
int main(){
  fastIO;
  int n;
  cin >> n;
  string s;
  cin >> s;
  string x,y;
  for(int i = 0;i < n;i ++ ){
    cin >> x;
    y = x.substr(5,3);
    x = x.substr(0,3);
    if(x == s)
      in ++ ;
    if(y == s)
      out ++ ;
  }
  if(in != out){
    cout << "contest";
  }
  else{
    cout << "home";
  }
  return 0;
}
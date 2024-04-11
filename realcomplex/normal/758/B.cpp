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

int main(){
  fastIO;
  char col[4] = {'R','B','Y','G'};
  sort(col , col + 4);
  string s;
  cin >> s;
  bool cor;
  int ri = 0 , bl = 0, yel = 0, gr = 0;
  do{
    cor = true;
    for(int i = 0;i < s.size();i ++ ){
      if(s[i] != '!')
        if(s[i] != col[i % 4])
          cor = false;
    }
    if(cor){
      for(int i = 0; i < s.size(); i++ ){
        if(s[i] == '!'){
          if(col[i % 4] == 'R') ri ++ ;
          else if(col[i % 4] == 'B') bl ++ ;
          else if(col[i % 4] == 'Y') yel ++ ;
          else gr ++ ;
        }
      }
      cout << ri << " " << bl << " " << yel << " " << gr << "\n";
      return 0;
    }
  }while(next_permutation(col, col + 4));
  return 0;
}
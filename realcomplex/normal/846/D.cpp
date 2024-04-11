#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

struct Pixel{
  int i_cor;
  int j_cor;
  int at_time;
};

vector<Pixel> broken;

const int N = 505;
int n,m,k,q;
int rect[N][N];

int ask(int x1, int y1, int x2, int y2){
  return rect[x2][y2] - rect[x1-1][y2] - rect[x2][y1-1] + rect[x1-1][y1-1];
}

bool is_broken(int check_time){ // is monitor broken at check_time
  memset(rect, 0, sizeof rect);
  for(Pixel it : broken){
    if(it.at_time <= check_time){
      rect[it.i_cor][it.j_cor] ++ ;
    }
  }
  int add;
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1;j <= m;j ++ ){
      add = rect[i - 1][j] + rect[i][j - 1] - rect[i - 1][j - 1];
      rect[i][j] += add;
    }
  } 
  int i1, j1, i2, j2;
  for(int i = 1;i <= n-k+1; i ++ ){
    for(int j = 1;j <= m-k+1;j ++ ){
      i1 = i;
      j1 = j;
      i2 = i+k-1;
      j2 = j+k-1;
      if(ask(i1,j1,i2,j2) == k*k){
        return true;
      }
    }
  }
  return false;
}

int main(){
  fastIO;
  cin >> n >> m >> k >> q;
  Pixel current;
  for(int i = 0;i < q;i ++ ){
    cin >> current.i_cor >> current.j_cor >> current.at_time;
    broken.push_back(current);
  }
  if(!is_broken((int)2e9 + 9)){
    cout << -1 << "\n";
    return 0;
  }
  int tl = 0, tr = (int)2e9 + 9;
  int check;
  while(tl < tr){
    check = tl+tr;
    check /= 2;
    if(is_broken(check)){
      tr = check;
    }
    else{
      tl = check + 1;
    }
  }
  cout << tr << "\n";
  return 0;
}
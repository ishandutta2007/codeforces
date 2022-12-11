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

const int N = 7;
int cub[3][N];
vector<int> can;

int rez;
int p[3];

int main(){
  //fastIO;
  int n;
  cin >> n;
  for(int i = 0;i<N;i++){
    for(int j = 0;j<3;j++){
      cub[j][i] = -1;
    }
  }
  for(int i = 0;i<n;i++){
    for(int j = 1;j<=6;j++)cin >> cub[i][j];
  }
  int ans = 0;
  int rz,cur;
  for(int x = 0;x<=6;x++){
    for(int y = 0;y<=6;y++){
      for(int z = 0;z<=6;z++){
        p[0] = cub[0][x];
        p[1] = cub[1][y];
        p[2] = cub[2][z];
        sort(p,p+3);
        do{
          rz = 1;
          cur = 0;
          for(int j = 2;j>=0;j--){
            if(p[j] == -1)
              continue;
            cur += p[j] * rz;
            rz *= 10;
          }
          can.push_back(cur);
        }while(next_permutation(p , p + 3));
      }
    }
  }
  sort(can.begin(),can.end());
  can.push_back(1232139);
  for(int i = 1;i<can.size();i++){
    if(can[i] - can[i-1] > 1){
      cout << can[i-1] << "\n";
      break;
    }
  }
  return 0;
}
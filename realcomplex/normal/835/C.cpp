#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
int smod[N][N][11];

vector<int>ibrig[N][N];
int main(){
   int n, q, c;
   cin >> n >> q >> c;
   ++ c;
   int xi, yi, si, ci;   
   for(int i = 0 ;i < n; i ++ ){
      cin >> xi >> yi >> si;
      ibrig[xi][yi].push_back(si);
   }
   int sm = 0;
   for(int t = 0 ; t < c; t ++ ){
   for(int i = 1 ;i < N;i ++ ){
      for(int j = 1 ; j < N; j ++ ){
	 sm = 0;
         for(auto x : ibrig[i][j])
            sm += (x + t) % c;
	 smod[i][j][t] = sm; 	
      }
   }
   for(int i = 1; i < N; i ++ ){
      for(int j = 1; j < N; j ++ ){
         smod[i][j][t] += smod[i - 1][j][t] + smod[i][j - 1][t] - smod[i - 1][j - 1][t];
      }
   }
   }
   int tim, x1, y1, x2, y2;
   for(int i = 0 ; i < q; i ++ ){
      cin >> tim >> x1 >> y1 >> x2 >> y2;
      tim %= c;
      cout << smod[x2][y2][tim] - smod[x1 - 1][y2][tim] - smod[x2][y1 - 1][tim] + smod[x1 - 1][y1 - 1][tim] << "\n";
   }
   
   return 0;
}
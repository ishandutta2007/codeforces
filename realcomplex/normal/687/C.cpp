#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

const int N = 505;

int dp[N][N];

int main(){
  int n, m;
  cin >> n >> m;
  int a;
  dp[0][0] = 1;
  for(int i = 1; i <= n; i ++ ){
     cin >> a;
     for(int j = m - a; j >= 0 ; j -- ){
        for(int t = m; t >= 0 ; t -- ){
          if(dp[j][t] == 1){
	     dp[j + a][t] = 1;
             if(t + a <= m)dp[j + a][t + a] = 1;
	  }     	
	
	}
     }
  }	
  vector<int> answ;
  for(int i = 0 ; i <= m; i ++ )
     if(dp[m][i])
	answ.push_back(i);
  cout << answ.size() << "\n";
  for(auto x : answ) cout << x << " ";
  return 0;
}
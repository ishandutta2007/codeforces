#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int lab[N];

int find(int x) {
  return (lab[x] < 0 ? x : lab[x] = find(lab[x]));
}


int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int ans = 0;

  memset(lab, -1, sizeof lab);

  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int x, y; cin >> x >> y;
    x = find(x); y = find(y);
    if(x != y) {
      ++ans;
      lab[y] = x;
    }
  }              

  cout << m - ans;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    

  return 0;
}
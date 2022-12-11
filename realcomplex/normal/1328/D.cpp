#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
  fastIO;
  int q;
  cin >> q;
  for(int i = 0 ;i  < q; i ++ ){
    int n;
    cin >> n;
    vector<int> ty(n);
    int dis = 0;
    for(int i = 0;  i < n ; i ++ ){
      cin >> ty[i];
      if(i && ty[i] != ty[i - 1]) dis ++ ;
    }
    if(ty[0] != ty[n-1]) dis ++ ;
    vector<int> col(n);
    col[0] = 1;
    for(int i = 0 ; i + 1 < n; i ++ ){
      if(ty[i] != ty[i + 1]){
        if(col[i] == 1) col[i + 1] = 2;
        else col[i + 1] = 1;
      }
      else{
        break;
      }
    }
    if(dis == n && n % 2 == 1) col[n-1]=3;
    else{
      for(int i = n-1;i >= 0 ; i -- ){
        if(col[i] != 0) break;
        if(ty[i] != ty[(i+1)%n]){
          if(col[(i+1)%n] == 1) col[i] = 2;
          else col[i] = 1;
        }
        else{
          col[i]=1;
        }
      }
    }
    int res = 0;
    for(int i = 0 ; i < n; i ++ )
      res = max(res, col[i]);
    cout << res << "\n";
    for(int i = 0 ; i < n; i ++ )
      cout << col[i] << " ";
    cout << "\n";
  }
  return 0;
}
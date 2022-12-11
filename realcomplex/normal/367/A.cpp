#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 9;
const int AL = 26;

int cnt[N][AL];
int ord(char x){
  return x-97;
}

int main(){
  string a;
  cin >> a;
  for(int i = 0;i<(int)a.size();i++){
    cnt[i+1][a[i]-97]++;
  } 
  for(int i = 1;i<N;i++){
    for(int j = 0;j<AL;j++)
      cnt[i][j]+=cnt[i-1][j];
  }
  int q;
  cin >> q;
  int l,r;
  int cx,cy,cz,k;
  int v;
  while(q--){
    cin >> l >> r;
    if(r-l+1<3)cout << "YES\n";
    else{
      cx=cnt[r][ord('x')]-cnt[l-1][ord('x')];
      cy=cnt[r][ord('y')]-cnt[l-1][ord('y')];
      cz=cnt[r][ord('z')]-cnt[l-1][ord('z')];
      k=r-l+1;
      if(cx==0||cy==0||cz==0){
        cout << "NO\n";
        continue;
      }
      v=abs(cx-cy)+abs(cz-cx)+abs(cz-cy);
      if(v<=2){
        cout << "YES\n";
      }
      else{
        cout << "NO\n";
      }
    }
  }
  return 0;
}
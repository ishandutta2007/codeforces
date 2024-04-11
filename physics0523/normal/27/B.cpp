#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> wc(n+1,0);
  vector<int> mc(n+1,0);
  int k=((n*(n-1))/2) - 1;
  for(int i=0;i<k;i++){
    int x,y;
    cin >> x >> y;
    wc[x]++;
    mc[x]++;mc[y]++;
  }

  int x=-1,y=-1;
  for(int i=1;i<=n;i++){
    if(mc[i]!=(n-1)){
      if(x==-1){x=i;}
      else{y=i;}
    }
  }
  if(wc[x]<wc[y]){swap(x,y);}
  cout << x << " " << y << "\n";
  return 0;
}
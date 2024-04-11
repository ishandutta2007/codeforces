#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,q;
  cin >> n >> m >> q;
  vector<int> arr(n*m,0);
  int ac=0;
  int res=0;

  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<m;j++){
      if(s[j]=='*'){
        arr[j*n+i]=1;
        ac++;
      }
    }
  }
  for(int i=0;i<ac;i++){
    if(arr[i]==0){res++;}
  }

  while(q>0){
    q--;
    int x,y;
    cin >> x >> y;
    x--;y--;
    int p=(y*n+x);

    if(arr[p]==0){
      if(arr[ac]==0){res++;}
      ac++;

      if(p<ac){res--;}
      arr[p]=1;
    }
    else{
      arr[p]=0;
      if(p<ac){res++;}

      ac--;
      if(arr[ac]==0){res--;}
    }
    cout << res << '\n';
  }
  return 0;
}
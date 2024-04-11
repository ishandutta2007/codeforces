#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  int tup[1048576][4];
  int res[1024][1024];
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        int v;
        cin >> v;
        tup[i*n+j][0]=i;
        tup[i*n+j][1]=j;
        tup[i*n+j][2]=v-1;
      }
    }
    int row=0,column=1,value=2;
    vector<int> os(4);
    string s;
    cin >> s;
    for(int i=0;i<m;i++){
      if(s[i]=='U'){os[row]+=(n-1);}
      if(s[i]=='D'){os[row]++;}
      if(s[i]=='L'){os[column]+=(n-1);}
      if(s[i]=='R'){os[column]++;}
      if(s[i]=='I'){swap(column,value);}
      if(s[i]=='C'){swap(row,value);}
    }
    os[0]%=n;os[1]%=n;os[2]%=n;
    for(int i=0;i<n*n;i++){
      //printf("%d %d %d\n",tup[i][0],tup[i][1],tup[i][2]);
      for(int j=0;j<3;j++){
        tup[i][j]+=os[j];
        tup[i][j]%=n;
      }
      //printf("%d %d %d\n",tup[i][0],tup[i][1],tup[i][2]);
      res[tup[i][row]][tup[i][column]]=tup[i][value];
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(j){cout << ' ';}
        cout << res[i][j]+1;
      }cout << '\n';
    }cout << '\n';
  }
}
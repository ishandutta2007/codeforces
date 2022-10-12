#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<string> s(n);
    int xcnt[4]={0};
    int ocnt[4]={0};

    for(int i=0;i<n;i++){
      cin >> s[i];
      for(int j=0;j<n;j++){
        if(s[i][j]=='X'){xcnt[(i+j)%3]++;}
        if(s[i][j]=='O'){ocnt[(i+j)%3]++;}
      }
    }

    int xt=0,ot=1;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(i==j){continue;}
        if(xcnt[i]+ocnt[j]<=xcnt[xt]+ocnt[ot]){
          xt=i;
          ot=j;
        }
      }
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(s[i][j]=='X' && (i+j)%3==xt){s[i][j]='O';}
        if(s[i][j]=='O' && (i+j)%3==ot){s[i][j]='X';}
      }
    }

    for(int i=0;i<n;i++){
      cout << s[i] << '\n';
    }
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    int tg=0,tk=0;
    for(int i=0;i<n;i++){
      cin >> s[i];
      for(int j=0;j<m;j++){
        if((i+j)%2==0){
          if(s[i][j]=='R'){tg|=1;}
          if(s[i][j]=='W'){tg|=2;}
        }
        else{
          if(s[i][j]=='R'){tk|=1;}
          if(s[i][j]=='W'){tk|=2;}
        }
      }
    }
    if(tg==3 || tk==3){cout << "No\n";continue;}
    if(tg==0 && tk==0){tg=1;tk=2;}
    if(tg==0){tg=3-tk;}
    if(tk==0){tk=3-tg;}
    if(tg==tk){cout << "No\n";continue;}
    cout << "Yes\n";
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if((i+j)%2==0){
          if(tg==1){cout << 'R';}else{cout << 'W';}
        }
        else{
          if(tk==1){cout << 'R';}else{cout << 'W';}
        }
      }cout << "\n";
    }
  }
  return 0;
}
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
    int cnt[4]={0};

    for(int i=0;i<n;i++){
      cin >> s[i];
      for(int j=0;j<n;j++){
        if(s[i][j]=='X'){cnt[(i+j)%3]++;}
      }
    }
    int tg;
    if(cnt[0]<=cnt[1] && cnt[0]<=cnt[2]){tg=0;}
    if(cnt[1]<=cnt[0] && cnt[1]<=cnt[2]){tg=1;}
    if(cnt[2]<=cnt[0] && cnt[2]<=cnt[1]){tg=2;}
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if((i+j)%3==tg && s[i][j]=='X'){
          s[i][j]='O';
        }
      }
    }

    for(int i=0;i<n;i++){
      cout << s[i] << '\n';
    }
  }
  return 0;
}
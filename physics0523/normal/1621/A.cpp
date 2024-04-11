#include<bits/stdc++.h>

using namespace std;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    if(ceil(n,2)<k){cout << "-1\n";continue;}
    int tg=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==tg && j==tg && k>0){
          k--;
          tg+=2;
          cout << "R";
        }
        else{
          cout << ".";
        }
      }cout << '\n';
    }
  }
  return 0;
}
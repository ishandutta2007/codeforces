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
    int n,m,k;
    cin >> n >> m >> k;
    int lg=ceil(n,m),sm=n/m;
    int lt=n-sm*m;
    int st=m-lt;
    int bas=0;
    for(int i=0;i<k;i++){
      int c=bas;
      for(int j=0;j<lt;j++){
        cout << lg;
        for(int k=0;k<lg;k++){
          cout << ' ' << c+1;
          c++;c%=n;
        }
        cout << '\n';
      }
      for(int j=0;j<st;j++){
        cout << sm;
        for(int k=0;k<sm;k++){
          cout << ' ' << c+1;
          c++;c%=n;
        }
        cout << '\n';
      }
      bas+=(lg*lt);bas%=n;
    }
  }
  return 0;
}
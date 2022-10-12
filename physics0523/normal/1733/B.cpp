#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,x,y;
    cin >> n >> x >> y;
    if(x>y){swap(x,y);}
    if(x!=0){cout << "-1\n";continue;}
    if(y==0){cout << "-1\n";continue;}
    if((n-1)%y){cout << "-1\n";continue;}
    int w=1,c=0;
    for(int i=2;i<=n;i++){
      if(i>2){cout << " ";}
      if(c==y){
        w=i;
        c=1;
      }
      else{
        c++;
      }
      cout << w;
    }cout << "\n";
  }
  return 0;
}
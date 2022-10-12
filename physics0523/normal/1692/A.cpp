#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b,c,d,e=0;
    cin >> a >> b >> c >> d;
    if(a<b){e++;}
    if(a<c){e++;}
    if(a<d){e++;}
    cout << e << '\n';
  }
  return 0;
}
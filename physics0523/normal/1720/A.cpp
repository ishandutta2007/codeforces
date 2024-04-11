#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    long long ad=a*d,bc=b*c;
    if(ad==bc){cout << "0\n";}
    else if((bc!=0 && ad%bc==0) || (ad!=0 && bc%ad==0)){cout << "1\n";}
    else{cout << "2\n";}
  }
  return 0;
}
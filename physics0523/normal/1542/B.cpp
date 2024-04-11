#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,a,b;
    cin >> n >> a >> b;
    bool fl=false;
    for(long long st=1;st<=n;st*=a){
      long long dist=n-st;
      if(dist%b==0){fl=true;break;}
      if(a==1){break;}
    }
    if(fl){cout << "Yes\n";}else{cout << "No\n";}
  }
  return 0;
}
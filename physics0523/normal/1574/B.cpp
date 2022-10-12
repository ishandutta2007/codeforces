#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b,c,m;
    cin >> a >> b >> c >> m;
    long long mxm=max(0ll,a-1)+max(0ll,b-1)+max(0ll,c-1);
    long long mini;
    long long me=max(a,max(b,c));
    long long rem=(a+b+c)-me;
    mini=max(0ll,me-(rem+1));
    if(mini<=m && m<=mxm){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k==0){cout << "1\n";continue;}
    string rs=s;
    reverse(rs.begin(),rs.end());
    if(s==rs){cout << "1\n";}
    else{cout << "2\n";}
  }
  return 0;
}
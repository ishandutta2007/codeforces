#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    vector<int> a(4);
    for(int i=0;i<4;i++){cin >> a[i];}
    vector<int> b(2);
    b[0]=max(a[0],a[1]);
    b[1]=max(a[2],a[3]);

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    if(a[0]==b[0] && a[1]==b[1]){cout << "Yes\n";}else{cout << "No\n";}
  }
  return 0;
}
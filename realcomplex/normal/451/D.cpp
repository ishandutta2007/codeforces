#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ans[2];
ll even[2],odd[2];

int main(){
  string a;
  cin >> a;
  int f;
  for(int i = 0;i<a.size();i++){
    if(a[i]=='a')f=0;
    else f=1;
    if(i%2==0){
      even[f]++;
      ans[1]+=even[f];
      ans[0]+=odd[f];
    }
    else{
      odd[f]++;
      ans[1]+=odd[f];
      ans[0]+=even[f];
    }
  }
  cout << ans[0] << " " << ans[1];
  return 0;
}
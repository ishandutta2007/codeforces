#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[200001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;cin>>tt;
  while (tt--){
    int n;cin>>n;

    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int maxx=1;
    int cnt=1;
    for (int i=2;i<=n;i++){
      if (a[i]==a[i-1]+1) cnt++;
      else cnt=1;
      maxx=max(maxx,cnt);
    }
    cout<<min(maxx,2)<<endl;
  }
  return 0;
}
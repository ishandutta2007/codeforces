#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k,p,x,y;
  cin >> n >> k >> p >> x >> y;
  vector<int> a(n,1);
  int cnt=0;
  for(int i=0;i<k;i++){
    cin >> a[i];
    if(a[i]>=y){cnt++;}
  }
  for(int i=k;i<n;i++){
    if(cnt<(n+1)/2){
      a[i]=y;
      cnt++;
    }
  }
  if(cnt<(n+1)/2){cout << "-1\n";return 0;}
  int sig=0;
  for(int i=0;i<n;i++){sig+=a[i];}
  if(sig>x){cout << "-1\n";return 0;}
  for(int i=k;i<n;i++){
    if(i!=k){cout << ' ';}
    cout << a[i];
  }cout << '\n';
  return 0;
}
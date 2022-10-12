#include<bits/stdc++.h>

using namespace std;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n+2);
  a[0]=1e9;a[n+1]=1e9;
  for(int i=1;i<=n;i++){cin >> a[i];}
  vector<int> ma=a;
  sort(ma.begin(),ma.end());

  // independent
  int res=ceil(ma[0],2)+ceil(ma[1],2);

  // # - #
  for(int i=1;i<=n;i++){
    res=min(res,ceil(a[i-1]+a[i+1],2));
  }

  // # #
  for(int i=1;i<n;i++){
    res=min(res,max(ceil(a[i]+a[i+1],3),ceil(max(a[i],a[i+1]),2)));
  }
  cout << res << '\n';
  return 0;
}
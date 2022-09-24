#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

typedef long long LL;

int n, k;
int a[400010];
map<int,int>mp;
LL ans;

int main(){

  scanf("%d%d", &n, &k);
  for(int i=0; i<n; i++)scanf("%d", a+i);
  int l=0, r=1;
  for(;r<=n; r++){
    mp[a[r-1]]++;
    for(;l<r && k<=mp[a[r-1]]; l++){
      mp[a[l]]--;
      ans+=n-r+1;
    }
  }
  cout<<ans<<endl;
      

  return 0;
}
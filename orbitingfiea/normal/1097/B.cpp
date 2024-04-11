#include<bits/stdc++.h>
using namespace std;

int n, a[22];

int main(){
  cin>>n;
  for (int i=0;i<n;++i) cin>>a[i];
  for (int S=0;S<(1<<n);++S){
    int sum=0;
    for (int i=0;i<n;++i)
      if (S>>i&1){
	sum+=a[i];
      }else{
	sum-=a[i];
      }
    if (sum%360==0){
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}
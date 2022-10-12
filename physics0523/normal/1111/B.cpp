#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k,m;
  cin >> n >> k >> m;
  vector<long long> a(n);
  for(int i=0;i<n;i++){cin >> a[i];}
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  double res=0.0;
  long long sig=0;
  for(int i=0;i<n;i++){
    sig+=a[i];
    long long rem=m-(n-1-i);
    if(rem<0){continue;}
    rem=min((i+1)*k,rem);
    res=max(((double)(sig+rem))/((double)(i+1)),res);
  }
  printf("%.12lf\n",res);
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sig=0,pre=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
      sig+=a[i];
    }
    sort(a.begin(),a.end());
    double res=-1.0e15;
    for(int i=0;i<n-1;i++){
      sig-=a[i];
      pre+=a[i];
      res=max(((double)sig/(double)(n-i-1.0))+((double)pre/(double)(i+1.0)),res);
    }
    printf("%.12lf\n",res);
  }
  return 0;
}
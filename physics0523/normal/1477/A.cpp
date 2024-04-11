#include<bits/stdc++.h>

using namespace std;

long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    sort(a.begin(),a.end());

    long long g=-1;
    for(int i=1;i<n;i++){
      if(i==1){g=a[i]-a[i-1];}
      else{g=llgcd(a[i]-a[i-1],g);}
    }

    long long ds=k-a[0];
    if(ds%g==0){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
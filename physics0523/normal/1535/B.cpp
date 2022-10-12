#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int res=0;
    for(int i=0;i<n;i++){
      for(int j=(i+1);j<n;j++){
        if(a[i]%2==0 || a[j]%2==0){res++;continue;}
        if(gcd(a[i],a[j])>1){res++;}
      }
    }
    cout << res << '\n';
  }
  return 0;
}
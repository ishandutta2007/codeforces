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
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){cin >> a[i] >> b[i];}
    int st=1,fi=n-1,te;
    while(st<=fi){
      te=(st+fi)/2;
      int f=te,g=0;
      for(int i=0;i<n;i++){
        if(f<=a[i] && g<=b[i]){f--;g++;}
      }
      if(f<0){st=te+1;}else{fi=te-1;}
    }
    cout << fi+1 << '\n';
  }
  return 0;
}
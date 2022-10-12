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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    vector<int> b(n,-1e9);
    int j=0;
    for(int i=0;i<n;i++){
      //cerr << "ok\n";
      b[j]=a[i];
      if(i==n-1){break;}
      j+=2;j%=n;
      while(b[j]>=0){j++;j%=n;}
    }

    bool fl=true;
    for(int i=0;i<n;i++){
      int j2=(i+n-1)%n;
      int k=(i+1)%n;
      if(b[j2]<b[i]&&b[i]>b[k]){continue;}
      if(b[j2]>b[i]&&b[i]<b[k]){continue;}
      fl=false;
      break;
    }

    if(!fl){cout << "NO\n";continue;}
    cout << "YES\n";
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << b[i];
    }cout << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;

    long long n,q;
    cin >> n >> q;
    vector<long long> a(n);
    long long s=0,x=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
      s+=a[i];
      x^=a[i];
    }

    // dummy
    int d1,d2;
    cin >> d1 >> d2;

    long long l=0,r=n;
    long long cl=0,cr=1;
    long long cs=a[0],cx=a[0];
    while(1){
      if(s-x == cs-cx){
        if(r-l > cr-cl){l=cl;r=cr;}
      }
      if(cl+1==cr || s-x > cs-cx){
        if(cr==n){break;}
        cs+=a[cr];
        cx^=a[cr];
        cr++;
      }
      else{
        cs-=a[cl];
        cx^=a[cl];
        cl++;
      }
    }
    cout << l+1 << " " << r << "\n";
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long r1,r2,r3,d;
  cin >> n >> r1 >> r2 >> r3 >> d;

  vector<long long> l(5,0);
  for(int i=0;i<n;i++){
    long long a;
    cin >> a;
    long long k1,k2;
    k1=r1*a+r3;
    k2=min({k1,r1*(a+2),r1+r2});
    //cout << i << '=' << k1 << ' ' << k2 << '\n';
    if(i==0){
      l[1]+=k1;
      l[2]+=k2;l[3]+=k2;l[4]+=k2;
    }
    else if(i==n-1){
      l[1]+=k1;l[2]+=k1;
      l[3]+=k2;l[4]+=k2;
      break;
    }
    else{
      vector<long long> nl(5,5e18);
      for(int p=1;p<=4;p++){
        for(int q=1;q<=4;q++){
          if(p%2==0 && q%2!=0){continue;}
          if(p==1 && q==1){nl[q]=min(nl[q],l[p]+k1);}
          else{nl[q]=min(nl[q],l[p]+k2);}
        }
      }
      l.swap(nl);
    }
    //cout << i << ':' << l[1] << ' ' << l[2] << ' ' << l[3] << ' ' << l[4] << '\n';
    for(int i=1;i<=4;i++){l[i]+=d*((long long)i);}
    //cout << i << ':' << l[1] << ' ' << l[2] << ' ' << l[3] << ' ' << l[4] << '\n';
  }
  cout << min({l[1],l[2],l[3],l[4]}) << '\n';
  return 0;
}
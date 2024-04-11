#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long r1=0;
    for(long long i=2;i<n;i++){
      long long md=max(i-1,n-i);
      r1+=md*md;
    }
    r1+=(n-1)*(n-1);
    cout << r1 << '\n';

    int m1=(n/2);
    int m2=m1+1;
    vector<int> p;
    p.push_back(m2);
    int pre=0,suf=0;
    for(int i=1;i<=n;i++){
      if(i==m1 || i==m2){continue;}
      if(i<m1){pre++;}else{suf++;}
      p.push_back(i);
    }
    p.push_back(m1);
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << p[i];
    }cout << '\n';
    cout << n-1 << '\n';
    for(int i=0;i<pre;i++){
      cout << p[n-1] << ' ' << n << '\n';
      int tg=p[n-1]-1;
      swap(p[tg],p[n-1]);
    }
    for(int i=0;i<suf;i++){
      cout << p[0] << ' ' << 1 << '\n';
      int tg=p[0]-1;
      swap(p[tg],p[0]);
    }
    cout << 1 << ' ' << n << '\n';
  }
  return 0;
}

// 5 1 2 3 6 7 8 9 4
// 5 2 3 4 6 7 8 9 1
// 9 2 3 4 5 6 7 8 1
// 1 2 3 4 5 6 7 8 9
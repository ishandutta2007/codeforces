#include<bits/stdc++.h>

using namespace std;

int f(int init,int sec){
  return max(0,init-2*sec);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    for(auto &nx : a){
      cin >> nx;
      nx--;
    }
    sort(a.begin(),a.end());

    vector<int> b;
    for(int i=0;i<m;i++){
      int d=a[(i+1)%m]-a[i];
      if(i==m-1){d+=n;}
      d--;
      if(d>0){b.push_back(d);}
    }
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    // for(auto &nx : b){cout << nx << ' ';}cout << "\n";
    int res=0,sec=0;
    for(auto &nx : b){
      int cur=f(nx,sec);
      if(cur==0){continue;}
      else if(cur==1){
        res++;
        sec+=1;
      }
      else{
        res+=(cur-1);
        sec+=2;
      }
    }
    cout << n-res << "\n";
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int L;
  cin>>L;
  for(int k=0;k<L;k++){
    int N;
    cin>>N;
    vector<int64_t> p;
    vector<int64_t> q;
    for(int i=0;i<N;i++){
      int64_t a;
      cin>>a;
      if(a<0){
        q.push_back(a);
      }
      else{
        p.push_back(a);
      }
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    sort(q.begin(),q.end());
    int l=p.size();
    int m=q.size();
    int64_t Z=-1671671771671671670;
    if(m>=5){
      int64_t B=1;
      for(int i=0;i<5;i++){
        B*=q[m-1-i];
      }
      Z=max(Z,B);
    }
    for(int i=1;i<min(6,l);i++){
      p[i]*=p[i-1];
    }
    for(int i=1;i<min(6,m);i++){
      q[i]*=q[i-1];
    }
    for(int i=max(0,5-l);i<=min(5,m);i++){
      int64_t A=1;
      if(i==0){
        A=p[4];
      }
      else if(i==5){
        A=q[4];
      }
      else{
        A=p[4-i]*q[i-1];
      }
      Z=max(Z,A);
    }
    cout<<Z<<endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    int M;
    cin>>M;
    vector<int> p(M);
    for(int i=0;i<M;i++){
      cin>>p[i];
    }
    vector<int> q=p;
    sort(p.begin(),p.end());
    vector<int> r;
    for(int i=0;i<M;i++){
      if(p[i]!=q[i]){
        r.push_back(p[i]);
      }
    }
    if(!r.size()){
      cout<<"YES"<<endl;
    }
    else{
      int A=p[0];
      int B=r.size();
      for(int i=0;i<B;i++){
        A=gcd(A,r[i]);
      }
      if(A==p[0]){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
  }
}
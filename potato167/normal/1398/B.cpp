#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    string S;
    cin>>S;
    vector<int> p;
    int M=S.size(),A=0,Z=0;
    for(int j=0;j<M;j++){
      if(S[j]=='0'){
        p.push_back(A);
        A=0;
      }
      else{
        A++;
      }
    }
    p.push_back(A);
    int K=p.size();
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    for(int j=0;j<K;j++){
      if(j%2==0){
        Z+=p[j];
      }
    }
    cout<<Z<<endl;
  }
}
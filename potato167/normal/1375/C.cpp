#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    int M;
    cin>>M;
    vector<int> p(M);
    for(int i=0;i<M;i++){
      cin>>p[i];
    }
    stack<int> s;
    s.push(p[0]);
    for(int i=1;i<M;i++){
      if(s.top()<p[i]){
        while(s.size()>1){
          if(s.top()<p[i]){
            s.pop();
          }
          else{
            break;
          }
        }
      }
      if(s.top()>p[i]){
        s.push(p[i]);
      }
    }
    if(s.size()==1){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }

}
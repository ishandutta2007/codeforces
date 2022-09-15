#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    int M;
    cin>>M;
    vector<int> p(M+2);
    p[0]=20001924167;
    p[M+1]=2001924167;
    for(int i=0;i<M;i++){
      cin>>p[i+1];
      p[i+1]=abs(p[i+1]);
    }
    int x=1;
    vector<int> q(M+2,1);
    for(int i=1;i<=M;i++){
      if(p[i-1]<=p[i]&&p[i]<=p[i+1]){
        q[i]*=x;
        x*=-1;
      }
      if(p[i-1]>p[i]&&p[i]>p[i+1]){
        q[i]*=x*-1;
        x*=-1;
      }
    }
    for(int i=1;i<=M;i++){
      cout<<p[i]*q[i];
      if(M==i){
        cout<<endl;
      }
      else{
        cout<<" ";
      }
    }
  }
      
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int Q;
  cin>>Q;
  for(int l=0;l<Q;l++){
    int N;
    cin>>N;
    int A=0,B=0;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      if(a){
        A++;
      }
      else{
        B++;
      }
    }
    if(B*2>=N){
      cout<<B<<endl;
      for(int i=0;i<B;i++){
        cout<<"0";
        if(i!=B-1){
          cout<<" ";
        }
      }
    }
    else{
      cout<<((N+3)/4)*2<<endl;
      for(int i=0;i<((N+3)/4)*2;i++){
        cout<<"1";
        if(i+1!=((N+3)/4)*2){
          cout<<" ";
        }
      }
    }
    cout<<endl;
  }
}
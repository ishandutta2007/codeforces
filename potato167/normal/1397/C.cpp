#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin>>N;
  if(N==1){
    int a;
    cin>>a;
    a*=-1;
    cout<<"1 1"<<endl;
    cout<<"0"<<endl;
    cout<<"1 1"<<endl;
    cout<<"0"<<endl;
    cout<<"1 1"<<endl;
    cout<<a<<endl;
  }
  else{
    vector<int64_t> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  cout<<"1 1"<<endl;
  cout<<N-p[0]<<endl;
  cout<<"2 "<<N<<endl;
  for(int i=1;i<N;i++){
    cout<<(N-1)*p[i];
    if(i!=N-1){
      cout<<" ";
    }
    else{
      cout<<endl;
    }
  }
  cout<<"1 "<<N<<endl;
  cout<<-1*N<<" ";
  for(int i=1;i<N;i++){
    cout<<N*(-1)*p[i];
    if(i!=N-1){
      cout<<" ";
    }
    else{
      cout<<endl;
    }
  }
  }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    if(a*2<=b){
      cout<<a<<" "<<2*a<<endl;
    }
    else{
      cout<<"-1 -1"<<endl;
    }
  }
}
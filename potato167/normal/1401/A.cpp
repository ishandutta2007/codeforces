#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    int a,b;
    cin>>a>>b;
    if(b>a){
      cout<<b-a<<endl;
    }
    else{
      a-=b;
      a%=2;
      cout<<a<<endl;
    }
  }
}
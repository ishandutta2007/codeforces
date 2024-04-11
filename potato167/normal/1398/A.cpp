#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    vector<int> p(a);
    for(int j=0;j<a;j++){
      cin>>p[j];
    }
    if(p[0]+p[1]<=p[a-1]){
      cout<<"1 2 "<<a<<endl;
    }
    else{
      cout<<"-1"<<endl;
    }
  }
}
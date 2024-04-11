#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    string S;
    int M;
    cin>>M>>S;
    map<int,int64_t> m;
    int64_t Z=0,A=0;
    m[0]=1;
    for(int j=0;j<M;j++){
      int64_t a=S[j]-'0';
      a--;
      A+=a;
      if(m.count(A)){
        Z+=m[A];
        m[A]++;
      }
      else{
        m[A]=1;
      }
    }
    cout<<Z<<endl;
  }
}
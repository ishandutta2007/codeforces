#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int j=0;j<N;j++){
    string S;
    cin>>S;
    int N=S.size();
    int Z=min(2,N);
    vector<int> p(100);
    vector<int> c(10);
    for(int i=0;i<N;i++){
      int b=S[i]-'0';
      c[b]++;
      for(int k=b;k<100;k+=10){
        if(p[k]%2==1){
          p[k]++;
        }
      }
      for(int k=b*10;k<b*10+10;k++){
        if(p[k]%2==0){
          p[k]++;
        }
      }
    }
    for(int i=0;i<10;i++){
      Z=max(Z,c[i]);
    }
    for(int i=0;i<100;i++){
      Z=max(Z,p[i]*(((p[i]%2)^1)));
    }
    cout<<N-Z<<endl;
  }
}
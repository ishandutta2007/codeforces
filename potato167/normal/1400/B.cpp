#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    int64_t A,B,Sc,Wc,Sw,Ww;
    cin>>A>>B>>Sc>>Wc>>Sw>>Ww;
    if(Sw*167167167-Sc>Ww*167167167-Wc){
      swap(Sw,Ww);
      swap(Sc,Wc);
    }
    if(A/Sw+B/Sw<=Sc){
      cout<<A/Sw+B/Sw<<endl;
    }
    else{
      int64_t Z=0;
      for(int i=0;i<=Sc;i++){
        if(A-i*Sw>=0&&B-(Sc-i)*Sw>=0){
          Z=max(Z,(A-i*Sw)/Ww+(B-(Sc-i)*Sw)/Ww);
        }
      }
      Z=min(Z,Wc);
      Z+=Sc;
      cout<<Z<<endl;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int j=0;j<N;j++){
    int64_t n,k,a,b,c,d;
    cin>>n>>k>>a>>b>>c>>d;
    if(a>c){
      swap(a,c);
      swap(b,d);
    }
    if(b<=c){
      int64_t x=c-b,y=d-a;
      if(k>=y*n){
        cout<<(x+y)*n+(k-y*n)*2<<endl;
      }
      else if(k<y){
        cout<<x+k<<endl;
      }
      else{
        cout<<(k/y)*(x+y)+min(x+k%y,(k%y)*2)<<endl;
      }
    }
    else{
      int64_t x=abs(a-c)+abs(b-d),A=0;
      k-=(min(b-c,d-c))*n;
      cout<<2*max(A,k-x*n)+max(A,min(k,x*n))<<endl;
    }
  }
}
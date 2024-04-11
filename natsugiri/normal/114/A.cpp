#include<iostream>
using namespace std;
int main(){
  int k,l,n;
  cin>>k>>l;
  n=-1;
  for(;l>1;){
    if(l%k==0){
      n++;
      l/=k;
    }else{
      n=-2;
      break;
    }
  }
  if(n<-1)cout<<"NO";
  else cout<<"YES\n"<<n<<endl;
  cout<<endl;
  return 0;
}
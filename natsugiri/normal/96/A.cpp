#include<iostream>
using namespace std;
int main(){
  int j;
  char c,d='2';
  for(j=0;cin>>c;){
    if(d==c){
      j++;
      if(j==7){
	cout<<"YES"<<endl;
	return 0;
      }
    }else j=1;
    d=c;
  }
  cout<<"NO"<<endl;
  return 0;
}
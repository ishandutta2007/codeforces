#include<iostream>
using namespace std;
int main(){
  int r,g,b,ans=0;
  cin>>r>>g>>b;
  if((r%2==0&&r-2<g)||r<=g){
    ans++;
    r=g;
  }
  if((r%2==0&&r-2<b)||r<=b){
    ans=2;
    r=b;
  }
  cout<<(r-1)/2*3+ans+30<<endl;

  return 0;
}
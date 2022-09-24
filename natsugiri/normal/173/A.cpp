#include<iostream>
#include<string>
using namespace std;

int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x/gcd(x,y)*y;}
char t[]="RSP";

int main(){
  int n,m,g;
  string A,B;
  cin>>n>>A>>B;
  m=lcm(A.size(),B.size());
  int a,b;
  a=b=0;

  for(int i=0;i<m;i++){
    char p=A[i%A.size()],q=B[i%B.size()];
    for(int j=0;j<3;j++){
      if(t[j]==p && t[(j+1)%3]==q)a++;
      else if(t[j]==q && t[(j+1)%3]==p)b++;
    }
  }
  a*=n/m;
  b*=n/m;
  
  for(int i=0;i<n%m;i++){
    char p=A[i%A.size()],q=B[i%B.size()];
    for(int j=0;j<3;j++){
      if(t[j]==p && t[(j+1)%3]==q)a++;
      else if(t[j]==q && t[(j+1)%3]==p)b++;
    }
  }
  cout<<b<<' '<<a<<endl;
  return 0;
}
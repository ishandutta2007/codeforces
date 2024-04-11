#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,k,i,j,a[10],m[10];
  string s,t[10];
  cin>>n>>k>>s;
  for(i=0;i<10;i++)a[i]=0;
  for(i=0;i<n;i++)a[s[i]-'0']++;
  for(i=0;i<10;i++){
    t[i]=s;
    m[i]=0;
    int c=a[i],x;
    for(x=1;;x++){
      for(j=0;j<n;j++){
	if(c>=k)break;
	if(t[i][j]-'0'==i+x){
	  c++;
	  m[i]+=x;
	  t[i][j]-=x;
	}
      }
      if(c>=k)break;
      for(j=n-1;j>=0;j--){
	if(c>=k)break;
	if(t[i][j]-'0'==i-x){
	  c++;
	  m[i]+=x;
	  t[i][j]+=x;
	}
      }
      if(c>=k)break;
    }
  }
  s=t[0];
  j=m[0];
  for(i=0;i<10;i++){
    if(m[i]<j||(m[i]==j&&t[i]<s)){
      s=t[i];
      j=m[i];
    }
  }
  cout<<j<<endl<<s<<endl;
  return 0;
}
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
  string str;
  int n,i,a[26],p,j,ans;
  memset(a,0,sizeof(a));
  cin>>str>>n;
  for(i=0;i<str.size();i++)a[str[i]-'a']++;
  for(j=0;j<26;j++){
    for(p=0,i=0;i<26;i++)if(a[p]<0||(a[i]>-1&&a[p]>a[i]))p=i;
    if(a[p]<=n){
      n-=a[p];
      a[p]=-1;
      for(i=0;i<str.size();i++){
	if(str[i]==p+'a'){
	  str[i]='0';
	}
      }
    }
  }
  ans=0;
  memset(a,0,sizeof(a));
  for(i=0;i<str.size();i++)if(str[i]!='0')a[str[i]-'a']++;
  for(i=0;i<26;i++)if(a[i])ans++;
  cout<<ans<<endl;
  for(i=0;i<str.size();i++)if(str[i]!='0')cout<<str[i];
  cout<<endl;
  return 0;
}
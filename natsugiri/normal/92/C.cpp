#include<iostream>
#include<string>
using namespace std;
int main(){
  int i,j,n,a[26][10001];
  string s,t;
  cin>>s>>t;
  for(i=0;i<26;i++)for(j=0;j<=s.size();j++)a[i][j]=-1;
  for(j=s.size()-1;j>-1;j--){
    for(i=0;i<26;i++){
      if(s[j]-'a'==i)a[i][j]=j;
      else a[i][j]=a[i][j+1];
    }
  }
  for(i=0;i<t.size();i++){
    if(a[t[i]-'a'][0]==-1){
      cout<<-1<<endl;
      return 0;
    }
  }
  for(j=n=0;j<t.size();){
    n++;
    for(i=0;;){
      if(a[t[j]-'a'][i]>-1){
    i=a[t[j]-'a'][i]+1;
    j++;
    if(j==t.size())break;
      }
      else break;
    }
  }
  cout<<n<<endl;
  return 0;
}
#include<iostream>
#include<string>

using namespace std;

string ans;


int exp(){
  string s;
  cin>>s;
  if(s=="int"){
    ans+=s;
    return 0;
  }
  if(s=="pair"){
    ans+="pair<";
    if(exp())return 1;
    ans+=',';
    if(exp())return 1;
    ans+='>';
    return 0;
  }
  return 1;
}
  

int main(){
  int n;
  cin>>n;
  string s;
  if(exp())cout<<"Error occurred"<<endl;
  else{
    if(cin>>s)cout<<"Error occurred"<<endl;
    else cout<<ans<<endl;
  }
  return 0;
}
#include <string.h>
#include <iostream>
using namespace std;
int alp[26];
int main(){
	string s,ans="";
	int k;
	cin>>k>>s;
	for(int i=0;i<s.size();i++){
			alp[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
			if(alp[i]%k){cout<<-1;return 0;}
			char tmp=char(i+'a');
			for(int j=0;j<alp[i]/k;j++)ans+=tmp;
	}
	for(int i=0;i<k;i++)cout<<ans;
	return 0;
}
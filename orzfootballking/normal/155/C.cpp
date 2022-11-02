#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	int k,ans=0;
	string x;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>x;
		int s1,s2;
		s1=s2=0;
		for(int j=0;j<s.size();j++){
			if(s[j]==x[0]){
				s1++;
			}else if(s[j]==x[1]){
				s2++;
			}else{
				ans+=min(s1,s2);s1=s2=0;
			}
		}
		ans+=min(s1,s2);
	}
	cout<<ans;
	return 0;
}
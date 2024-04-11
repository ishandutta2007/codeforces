#include <bits/stdc++.h> 
using namespace std;
char yy(char x,char y){
	for(int i='a';i<='z';i++){
		if(i!=x&&i!=y)return i;
	}
}
int main(){
	string s1,s2,ans;
	int n,t,i,j,k,m;
	vector<int> v1,v2;
	cin>>n>>t>>s1>>s2;
	for(i=0;i<n;i++){
		if(s1[i]!=s2[i])v2.push_back(i);
		else v1.push_back(i);
	}
	if(t<(v2.size()+1)/2){
		cout<<-1;return 0;
	}
	ans=s1;
	if(t<=v2.size()){
		m=2*v2.size()-2*t;
		for(i=0;i<m;i++){
			if(i%2==1)ans[v2[i]]=s2[v2[i]];
		}
		for(i=m;i<v2.size();i++){
			ans[v2[i]]=yy(s1[v2[i]],s2[v2[i]]);
		}
	}else{
		for(i=0;i<v2.size();i++){
			ans[v2[i]]=yy(s1[v2[i]],s2[v2[i]]);
		}
		t-=v2.size();
		for(i=0;i<t;i++){
			ans[v1[i]]=yy(s1[v1[i]],s2[v1[i]]);
		}
	}
	cout<<ans;
	return 0;
}
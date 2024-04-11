#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int n,i,a[50],x[9999];
	bool p[9999];
	string s;
	cin>>s;
	n=0;
	for(i=0;i<9999;i++)p[i]=1;
	for(i=2;i*i<9999;i++){
		if(p[i]){
			for(int j=i;i*j<9999;j++){
				p[i*j]=0;
			}
		}
	}
	p[0]=p[1]=0;
	for(i=0;i<50;i++)a[i]=0;
	for(i=0;i<s.size();i++){
		a[s[i]-'a']++;
	}
	n=0;
	int m=0,j;
	for(i=0;i<9999;i++)x[i]=0;
	for(i=1;i<=s.size();i++){
		if(p[i]&&i*2<=s.size()){
			for(j=i;j<=s.size();j+=i)x[j]=1;
		}
	}
	for(i=1;i<=s.size();i++)n+=x[i];
	for(i=0;i<26;i++){
		if(m<a[i]){
			j=i;
			m=a[i];
		}
	}
	if(m<n){
		puts("NO");
		return 0;
	}
	for(i=1;i<=s.size();i++){
		if(x[i]==1){
			s[i-1]='a'+j;
			a[j]--;
		}
	}
	j=0;
	for(i=1;i<=s.size();i++){
		if(x[i]==0){
			for(;a[j]==0;j++);
			s[i-1]='a'+j;
			a[j]--;
		}
	}
	cout<<"YES\n"<<s<<endl;
}
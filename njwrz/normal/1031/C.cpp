#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
vector<int> v1,v2; 
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b;
	cin>>a>>b;
	int s=0,t=1;
	while(s+t<=a+b){
		s+=t;t++;
	}
	for(int i=t-1;i>=1;i--){
		if(a>b){
			a-=i;v1.push_back(i);
		}else{
			b-=i;v2.push_back(i);
		}
	} 
	cout<<v1.size()<<'\n';
	for(int i=0;i<v1.size();i++)cout<<v1[v1.size()-i-1]<<' ';
	cout<<'\n';
	cout<<v2.size()<<'\n';
	for(int i=0;i<v2.size();i++)cout<<v2[v2.size()-i-1]<<' ';
	return 0;
}
#include <bits/stdc++.h> 
using namespace std;
int read(){
    int w=1,q=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0'&&ch<='9')
    	q=q*10+ch-'0',ch=getchar();
    return w*q;
}
int m,n;
vector<int> v[200005];
int main(){
	int x;
	n=read();m=read();
	for(int i=1;i<=n;i++){
		x=read();
		for(int j=0;x;j++,x/=2){
			v[x].push_back(j);
		}
	}
	int ans=1000000000,t;
	for(int i=200000;i>=0;i--){
		if(v[i].size()>=m){
			t=0;
			sort(v[i].begin(),v[i].end());
			for(int j=0;j<m;j++)t+=v[i][j];
			ans=min(ans,t);
		}
	}
	cout<<ans;
	return 0;
}
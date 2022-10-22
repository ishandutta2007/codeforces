#include<bits/stdc++.h>
using namespace std;
int a[5001],d[5001],p[5001],shuchu[5001];
int main(){
	int n,m,i,f=0;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];if(d[a[i]]==m)f=1;
		d[a[i]]++;
	}
	if(f){
		cout<<"NO";return 0;
	}
	cout<<"YES"<<endl;
	int o=0,l=0;
	while(o<m){
		o++;
		fill(p,p+5001,0);
		for(i=0;i<n;i++){
			if(d[a[i]]>0&&p[a[i]]==0&&shuchu[i]==0){
				p[a[i]]=1;d[a[i]]--;shuchu[i]=o;l++;
			}
			if(m-o==n-l)break;
		}
	}
	for(i=0;i<n;i++)cout<<shuchu[i]<<" ";
	return 0;
}
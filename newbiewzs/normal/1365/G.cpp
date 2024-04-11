#include<bits/stdc++.h>
#define cl (fflush(stdout))
#define int long long
using namespace std;
int n;
int p[5000],top;
int pos[6500];
vector<int>v[14];
int da[15];
signed main(){
	for(int i=1;i<(1<<13);i++){
		int zs=0;
		int u=i;
		while(u){
			u-=((u&(-u)));
			zs++;
		}
		if(zs==6)p[++top]=i;
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=13;k++){
			if(p[i]&(1<<(k-1)))v[k].push_back(i);
		}
	}
	for(int i=1;i<=13;i++){
		if(!v[i].size())continue;
		cout<<"?"<<" "<<v[i].size()<<" ";
		for(int k=0;k<v[i].size();k++){
			cout<<v[i][k]<<" ";
		}
		puts("");
		cl;
		cin>>da[i];
	}
	cout<<"! ";
	for(int i=1;i<=n;i++){
		int aa=0;
		for(int k=1;k<=13;k++){
			if(!(p[i]&(1<<(k-1)))){
				aa|=da[k];
			}
		}
		cout<<aa<<" ";
	}
	cl;
	return 0;
}
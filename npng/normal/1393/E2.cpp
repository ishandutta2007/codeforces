#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=100000;
const int Maxl=1000000;
const int Mod=1000000007;
int n;
string s[Maxn+5];
int len[Maxn+5];
vector<int> f[Maxn+5];
int f_1[Maxl+5],f_2[Maxl+5];
char s_1[Maxl+5],s_2[Maxl+5];
int lcp[Maxl+5];
void work(int x){
	int n=max(len[x-1],len[x])+2;
	for(int i=0;i<=n+2;i++){
		lcp[i]=f_1[i]=f_2[i]=0;
		s_1[i]=s_2[i]='a'-1;
	}
	for(int i=0;i<=len[x-1];i++){
		f_1[i]=f[x-1][i];
	}
	for(int i=0;i<len[x-1];i++){
		s_1[i]=s[x-1][i];
	}
	for(int i=0;i<len[x];i++){
		s_2[i]=s[x][i];
	}
	for(int i=n+1;i>=0;i--){
		if(s_1[i]==s_2[i]){
			lcp[i]=lcp[i+1]+1;
		}
		else{
			lcp[i]=0;
		}
	}
	int sum_1=0,sum_2=0;
	int flag=0;
	for(int i=0;i<=n;i++){
		if(i>0){
			if(s_1[i]<s_2[i-1]){
				sum_2=(sum_2+sum_1)%Mod;
				sum_1=0;
			}
			if(s_1[i]>s_2[i-1]){
				sum_1=0;
			}
		}
		if(flag==0){
			sum_1=(sum_1+f_1[i])%Mod;
		}
		if(flag==1){
			sum_2=(sum_2+f_1[i])%Mod;
		}
		f_2[i]=sum_2;
		if(flag==0){
			if(s_1[i]<s_2[i]){
				flag=1;
			}
			if(s_1[i]>s_2[i]){
				flag=-1;
			}
		}
		int p=i+1+lcp[i+1];
		if(p>n||s_1[p]<s_2[p]){
			f_2[i]=(f_2[i]+sum_1)%Mod;
		}
	}
	sum_1=sum_2=0;
	for(int i=n;i>=0;i--){
		int p=lcp[0];
		if(p>=i){
			f_2[i]=(f_2[i]+sum_1)%Mod;
		}
		else if(s_1[p]<s_2[p]){
			f_2[i]=(f_2[i]+sum_1)%Mod;
			f_2[i]=(f_2[i]+sum_2)%Mod;
		}
		int pos=i+1+lcp[i+1];
		if(pos>n||s_1[pos]<s_2[pos]){
			sum_1=(sum_1+f_1[i])%Mod;
		}
		else{
			sum_2=(sum_2+f_1[i])%Mod;
		}
		if(s_1[i-1]<s_2[i]){
			sum_1=(sum_1+sum_2)%Mod;
			sum_2=0;
		}
		if(s_1[i-1]>s_2[i]){
			sum_2=(sum_2+sum_1)%Mod;
			sum_1=0;
		}
	}
	for(int i=0;i<=len[x];i++){
		f[x][i]=f_2[i];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		len[i]=s[i].size();
		f[i].resize(len[i]+1);
	}
	for(int i=0;i<=len[1];i++){
		f[1][i]=1;
	}
	for(int i=2;i<=n;i++){
		work(i);
	}
	int ans=0;
	for(int i=0;i<=len[n];i++){
		ans=(ans+f[n][i])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}
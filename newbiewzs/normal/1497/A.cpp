#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
int T,n;
const int N=2e5+55;
int a[N]; 
int tong[N];
int st[N],top;
int main(){
	T=read();
	while(T--){
		n=read();top=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			tong[a[i]]++;
			if(tong[a[i]]==1)st[++top]=a[i];
		}
		sort(st+1,st+top+1);
		for(int i=1;i<=top;i++){
			cout<<st[i]<<" ";
		}
		for(int i=0;i<=100;i++){
			if(tong[i]>=2){
				for(int k=2;k<=tong[i];k++){
					cout<<i<<" ";
				}
			}
			tong[i]=0;
		}
		cout<<endl;
	}
	return 0;
}
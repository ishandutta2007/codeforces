#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int x=1;
	int s=0;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
int T;
char a[105];
int n;
int main(){
	cin>>T;
	while(T--){
		scanf("%s",a+1);
		n=strlen(a+1);
		bool flag=0;
		for(int i=1;i<=n;i++){
			int cnt0=0,cnt1=0;
			for(int k=1;k<=i;k++){
				if(a[k]=='0')cnt0++;
				else cnt1++;
			}
			bool bj=0;int pre;
			if(cnt0){
				pre=-1;
				for(int k=1;k<=i;k++){
					if(a[k]=='1'){
						if(pre==k-1)bj=1;
						pre=k;
					}
				}
				pre=-1;
				for(int k=i+1;k<=n;k++){
					if(a[k]=='0'){
						if(pre==k-1)bj=1;
						pre=k;
					}
				}
			}
			else{
				pre=-1;
				for(int k=i+1;k<=n;k++){
					if(a[k]=='0'){
						if(pre==k-1)bj=1;
						pre=k;
					}
				}
			}
			if(!bj){
				flag=1;
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}
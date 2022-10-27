#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[300001],s[300002];
int st[300001],top;
int l[300001],len[300001];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",a+i),s[i]=len[i]=0;
		st[top=0]=0;
		for(int i=1;i<=n;i++){
			while(top&&a[st[top]]>=a[i]) top--;
			l[i]=st[top]+1,st[++top]=i;
		}
		st[top=0]=n+1;
		for(int i=n;i;i--){
			while(top&&a[st[top]]>=a[i]) top--;
			len[a[i]]=max(len[a[i]],st[top]-l[i]),st[++top]=i;
		}
		for(int i=1;i<=n;i++) s[min(len[i],n-i+1)+1]++;
		for(int i=1,tp=n;i<=n;i++){
			tp-=s[i];
			putchar((tp==n-i+1)+'0');
		}
		putchar('\n');
	}
}
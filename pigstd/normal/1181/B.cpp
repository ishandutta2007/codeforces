#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
char s[M],r[M],a[M],b[M],m[M];
int ans[M],l,sum=M+10,f=1,lenm;
int main(){
	cin>>l>>s+1;for (int i=2;i<=l;i++)if (s[i]!='0')sum=min(sum,max(i-1,l-i+1));
	for (int i=2;i<=l;i++)if (s[i]!='0'&&abs(sum-max(i-1,l-i+1))<=1){
			memset(a,0,sizeof(a)),memset(b,0,sizeof(b)),memset(ans,0,sizeof(ans)),memset(r,0,sizeof(r));int len1=0,len2=0;
			for (int j=1;j<i;j++)a[len1++]=s[j];for (int j=i;j<=l;j++)b[len2++]=s[j];int len=max(len1,len2);
			for (int i=0;i<len1/2;i++)swap(a[i],a[len1-i-1]);for (int i=0;i<len2/2;i++)swap(b[i],b[len2-i-1]);
			for (int i=strlen(a);i<len;i++)a[i]='0';for (int i=strlen(b);i<len;i++)b[i]='0';
			for (int i=0;i<len;i++){ans[i]+=(a[i]-'0'+b[i]-'0');if (ans[i]>=10)ans[i+1]++,ans[i]-=10;}
			if (ans[len]!=0)len++;for (int i=0;i<len;i++)r[i]=ans[len-i-1]+'0';
			if (f){f=0;for (int i=0;i<len;i++)m[i]=r[i];lenm=len;continue;}if (lenm<len)continue;
			if (lenm>len){for (int i=0;i<len;i++)m[i]=r[i];lenm=len;}
			if (lenm==len){
				int k=-1;for (int i=0;i<len;i++)
				if (r[i]<m[i]){k=1;break;}else if (r[i]>m[i]){k=0;break;}
				if (k==1)for (int i=0;i<len;i++)m[i]=r[i];}}
	for (int i=0;i<lenm;i++)cout<<m[i];
	return 0;
}
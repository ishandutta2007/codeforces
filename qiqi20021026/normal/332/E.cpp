#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

char s1[1200000],s2[1200000];
int n,m,p;
string tmp,ans;

int main(){
	gets(s1+1);; gets(s2+1); scanf("%d",&n);
	int m=strlen(s1+1),p=strlen(s2+1);
	for (int i=1;i<=n;i++) ans=ans+"2";
	for (int i=m+1;i<=n+m;i++) s1[i]='?';
	for (int i=p+1;i<=n+m;i++) s2[i]='?';
	for (int i=1;i<=min(n,p);i++){
		int k=n,ss=0;
		tmp="";
		for (int j=i;j>=1;j--){
			bool flag=1;
			for (;k>=1 && flag;k--){
				flag=0;
				for (int l=1;(l-1)*n+k<=m || (l-1)*i+j<=p;l++)
					if (s1[(l-1)*n+k]!=s2[(l-1)*i+j]){flag=1; break;}
				if (!flag){tmp="1"+tmp; ss++;} else tmp="0"+tmp;
			}
		}
		if (ss<i) continue;
		for (;k>=1;k--) tmp="0"+tmp;
		if (tmp<ans) ans=tmp;
	}
	cout<<((ans[0]=='2')?("0"):ans)<<endl;
	
	return 0;
}
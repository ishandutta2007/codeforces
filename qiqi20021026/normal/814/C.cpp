#include<iostream>
#include<cstdio>

using namespace std;

#define LL long long

int n,i,q,ans,t,w,x;
char ch;
int s[1530],f[255][1530];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		s[i]=getchar();
		while (s[i]<'a' || s[i]>'z') s[i]=getchar();
	}
	
	for (int i=1;i<=n;i++){
		for (int j='a';j<='z';j++)
			f[j][i]=f[j][i-1]+1;
		f[s[i]][i]--;
	}
	
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		scanf("%d",&x);
		ch=getchar();
		while (ch<'a' || ch>'z') ch=getchar();
		ans=0;
		t=1;
		w=1;
		while (t<=w && w<=n){
			if (f[ch][w]-f[ch][t-1]>x) t++;
			else{
				if (ans<w-t+1) ans=w-t+1;
				w++;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
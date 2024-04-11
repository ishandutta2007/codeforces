#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000009;
int n,m;
char s[500005],t[500005];
int h[500005],bas[500005],cnt[5];

int main(){
	scanf("%s%s",s+1,t+1); n=strlen(s+1); m=strlen(t+1);
	for(int i=1;i<=m;i++) h[i]=(7ll*h[i-1]%cys+t[i]-'0'+1)%cys;
//	for(int i=1;i<=m;i++) cout<<h[i]<<' ';
//	cout<<endl;
	bas[0]=1;
	for(int i=1;i<=m;i++) bas[i]=7ll*bas[i-1]%cys;
	int x=0;
	for(int i=m-1;i>=1;i--){
		if(h[i]==(h[m]-1ll*h[m-i]*bas[i]%cys+cys)%cys){
			x=i;
			break;
		}
	}
//	cout<<x<<endl;
	for(int i=1;i<=n;i++) cnt[s[i]-'0']++;
	int now=1;
	for(int i=1;i<=n;i++){
//		cout<<"TEST "<<i<<' '<<now<<endl;
		if(cnt[t[now]-'0']){
			cnt[t[now]-'0']--,now++;
			printf("%c",t[now-1]);
		}
		else{
			for(int j=i;j<=n;j++) printf("%c",((t[now]-'0')^1)+'0');
			printf("\n");
			return 0;
		}
		if(now==m+1) now=x+1;
	}
	printf("\n");
	return 0;
}
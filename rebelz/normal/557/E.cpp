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
int n,k,root=1,cnt=1;
int h1[5005],h2[5005],sum[20000005],siz[20000005],bas[5005],f[5005][5005],ch[20000005][2];
char s[5005];

int mod(int x){return x>=cys?x-cys:x;}

int hsh1(int l,int r){
	if(l==1) return h1[(r-1)/2*2+1];
	else return mod(h1[(r-l)/2*2+l]-1ll*h1[l-2]*bas[(r-l)/2+1]%cys+cys);
}

int hsh2(int l,int r){
	return mod(h2[r-(r-l)/2*2]-1ll*h2[r+2]*bas[(r-l)/2+1]%cys+cys);
}

void insert(char *s,int lt){
	int m=strlen(s+1),p=root;
	for(int i=1;i<=m;i++){
		if(!ch[p][s[i]-'a']) ch[p][s[i]-'a']=++cnt;
		p=ch[p][s[i]-'a'];
		siz[p]+=f[lt][lt+i-1];
	}
}

void dfs(int u){
	if(k<=siz[u]) return;
	k-=siz[u];
	for(int i=0;i<=1;i++){
		if(!ch[u][i]) continue;
		if(k<=sum[ch[u][i]]){
			printf("%c",'a'+i);
			dfs(ch[u][i]);
			return;
		}
		k-=sum[ch[u][i]];
	}
}

int main(){
	scanf("%s%d",s+1,&k); n=strlen(s+1);
	h1[1]=s[1]-'a'+1,bas[0]=1;
	for(int i=1;i<=n;i++) bas[i]=7ll*bas[i-1]%cys;
	for(int i=2;i<=n;i++) h1[i]=mod(7ll*h1[i-2]%cys+s[i]-'a'+1);
	for(int i=n;i>=1;i--) h2[i]=mod(7ll*h2[i+2]%cys+s[i]-'a'+1);
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) if(hsh1(i,(i+j)/2)==hsh2((i+j+1)/2,j)) f[i][j]=1;
	for(int i=1;i<=n;i++) insert(s+i-1,i);
	for(int i=cnt;i>=1;i--) sum[i]=siz[i]+sum[ch[i][0]]+sum[ch[i][1]];
	dfs(1);
	return 0;
}
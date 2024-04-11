#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

char s[255][255];
int n,m,len,base=29;
int r[505],l[505];
ll h[255][255][255],ch[505],ch2[505],num[30],cnt[30];
bool flag[255][255][255];

int manachar(int len){
	memset(ch,-1,sizeof(ch));
	for(int i=len-1;i>=0;i--) ch[i*2+1]=ch2[i];
	len=2*len+1;
	int pos=0,maxright=0,ans=0;
	for(int i=1;i<len;i++){
		r[i]=1;
		if(i<=maxright) r[i]=min(r[pos*2-i],maxright-i+1);
		for(int j=r[i];j<=len;j++){
			if(i-j<0||i+j>len||ch[i-j]!=ch[i+j]) break;
			r[i]=j+1;
		}
		if(i+r[i]-1>maxright) maxright=i+r[i]-1,pos=i;
		ans+=r[i]/2;
	}
	return ans;
}

int main(){
	srand(time(0)+clock());
	n=readint(); m=readint();
	for(int i=0;i<26;i++) num[i]=(rand()<<25)+rand();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) h[i][j][j]=num[s[i][j]-'a'];
	int f=0;
	for(int i=1;i<=n;i++){
		for(int l=1;l<=m;l++){
			memset(cnt,0,sizeof(cnt)); cnt[s[i][l]-'a']=1; f=1;
			for(int r=l+1;r<=m;r++){
				cnt[s[i][r]-'a']^=1; if(cnt[s[i][r]-'a']==1) f++; else f--;
				h[i][l][r]=h[i][l][r-1]+num[s[i][r]-'a'];
				if(f>1) flag[i][l][r]=true;
			}
		}
	}
	ll ret=0;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			int g=0;
			flag[n+1][i][j]=true;
			for(int k=1;k<=n+1;k++){
				if(!flag[k][i][j]) ch2[k-g-1]=h[k][i][j];
				else ret+=manachar(k-g-1),g=k;
			}
		}
	}
	printf("%lld\n",ret);
	return 0;
}
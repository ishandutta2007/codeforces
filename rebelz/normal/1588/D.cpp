// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int now[55],len[15],nxt[15][110][55],per[55][110],pos[55][55][2],d[55][1100];
pii opt[55][1100];
char s[15][110];

int id(char ch){return ch>='a'&&ch<='z'?ch-'a':ch-'A'+26;}
char getc(int x){return x<26?x+'a':x-26+'A';}

void print(int u,int x,int y){
	if(!u) return;
	print(u-1,opt[x][y].fi,opt[x][y].se);
	putchar(getc(x));
}

int main(){
	int T=readint();
	while(T--){
		memset(nxt,0,sizeof(nxt));
		memset(per,0,sizeof(per));
		memset(pos,0,sizeof(pos));
		n=readint();
		for(int i=0;i<n;i++) scanf("%s",s[i]+1);
		for(int i=0;i<n;i++){
			len[i]=strlen(s[i]+1);
			for(int j=0;j<52;j++) now[j]=len[i]+1;
			for(int j=len[i];j>=0;j--){
				for(int k=0;k<52;k++) nxt[i][j][k]=now[k];
				if(j){
					if(now[id(s[i][j])]) per[i][now[id(s[i][j])]]=1,pos[i][id(s[i][j])][1]=now[id(s[i][j])];
					now[id(s[i][j])]=j;
				}
			}
			for(int j=0;j<52;j++) if(now[j]<=len[i]) pos[i][j][0]=now[j];
		}
		memset(d,-0x3f,sizeof(d));
		int ans=0; pii cho;
		for(int i=0;i<52;i++){
			int to=0,fl=0;
			for(int j=0;j<n;j++){
				int pl=nxt[j][0][i];
				if(pl>len[j]) fl=1;
				else to|=per[j][pl]<<j;
			}
			if(!fl) d[i][to]=1,ans=1,cho=mp(i,to);
		}
		for(int i=1;i<=len[0];i++){
			int ch=id(s[0][i]);
			for(int j=0;j<(1<<n);j++){
				if((j&1)!=per[0][i]) continue;
				if(d[ch][j]<0) continue;
				if(chkmax(ans,d[ch][j])) cho=mp(ch,j);
				for(int k=0;k<52;k++){
					int to=0,fl=0;
					for(int l=0;l<n;l++){
						int pl=nxt[l][pos[l][ch][(j>>l)&1]][k];
						if(pl>len[l]) fl=1;
						else to|=per[l][pl]<<l;
					}
					if(fl) continue;
					if(chkmax(d[k][to],d[ch][j]+1)) opt[k][to]=mp(ch,j);
				}
			}
		}
		printf("%d\n",ans);
		print(ans,cho.fi,cho.se);
		putchar('\n');
	}
	return 0;
}
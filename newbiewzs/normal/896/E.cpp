#include<bits/stdc++.h>
using namespace std;
char aa;
const int N=1e6+5;
const int M=5e5+5;
const int B=1000;
int n,m,cn,a[N];
int opt[M],l[M],r[M],x[M];
int f[N],zuo,you;
int da[M];
int rt[M];
int siz[N];
int maxx;
int bj;
char bb;
inline int find(int z){
	if(f[z]!=z)return f[z]=find(f[z]);
	return z;
}
namespace OUTPUT_SPACE{
    char ss[19455555],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
    inline int Flush() { return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0; }
}using OUTPUT_SPACE::print;using OUTPUT_SPACE::Flush;
namespace INPUT_SPACE{
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
    inline int gc()
    {
        if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
        return (HD==TL)?EOF:*HD++;
    }
	inline int read()
    {
        int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
        while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
    }
}using INPUT_SPACE::read;
signed main(){
//	freopen("data.in","r",stdin);
//	freopen("ss.out","w",stdout);
//	cout<<((&aa-&bb)/1024/1024);
	n=read();m=read();
	cn=(n-1)/B+1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++){
		opt[i]=read();l[i]=read();r[i]=read();x[i]=read();
	}
	for(int i=1;i<=cn;i++){
		zuo=(i-1)*B+1;you=min(n,i*B);
		maxx=0;bj=0;
		for(int k=zuo;k<=you;k++){
			if(!rt[a[k]])rt[a[k]]=k,f[k]=k,siz[k]++;
			else f[k]=rt[a[k]],siz[rt[a[k]]]++;
			maxx=max(maxx,a[k]);
		}
		for(int k=1;k<=m;k++){
			if(you<l[k] or zuo>r[k])continue;
			if(opt[k]==1){
				if(zuo>=l[k] and you<=r[k]){
					if(maxx-bj<=x[k])continue;
					if(x[k]*2>=maxx-bj){
						for(int j=x[k]+1+bj;j<=maxx;j++){
							if(!rt[j])continue;
							if(!rt[j-x[k]]){
								rt[j-x[k]]=rt[j];
								a[rt[j-x[k]]]=j-x[k];
								rt[j]=0;
							}
							else{
								f[rt[j]]=rt[j-x[k]];
								siz[rt[j-x[k]]]+=siz[rt[j]];
								siz[rt[j]]=0;
								rt[j]=0;
							}
						}
						maxx=min(maxx,x[k]+bj);
					}
					else{
						for(int j=bj+1;j<=x[k]+bj;j++){
							if(!rt[j])continue;
							if(!rt[j+x[k]]){
								rt[j+x[k]]=rt[j];
								a[rt[j+x[k]]]=j+x[k];
								rt[j]=0;
							}
							else{
								f[rt[j]]=rt[j+x[k]];siz[rt[j+x[k]]]+=siz[rt[j]];
								siz[rt[j]]=0;rt[j]=0;
							}
						}
						bj+=x[k];
					}
					
				}
				else{
					maxx=0;
					for(int j=zuo;j<=you;j++)
					{
						a[j]=a[find(j)];
						siz[j]=0;rt[a[j]]=0;
					}
					for(int j=zuo;j<=you;j++)a[j]-=bj;
					bj=0;
					for(int j=max(zuo,l[k]);j<=min(you,r[k]);j++){
						f[j]=0;
						if(a[j]>x[k])a[j]-=x[k];
					}
					for(int 
					j=zuo;j<=you;j++){
						maxx=max(maxx,a[j]);
						if(!rt[a[j]])rt[a[j]]=j,f[j]=j,siz[rt[a[j]]]=1;
						else f[j]=rt[a[j]],siz[rt[a[j]]]++;
					}
				}
			}
			else{
				if(zuo>=l[k] and you<=r[k]){
					da[k]+=siz[rt[x[k]+bj]];
				}
				else{
					for(int j=max(zuo,l[k]);j<=min(you,r[k]);j++){
						a[j]=a[find(j)];
						if(a[j]-bj==x[k])da[k]++;
					}
				}
			}
		}
		for(int k=zuo;k<=you;k++)rt[a[k]]=0;
	}
	for(int i=1;i<=m;i++){
		if(opt[i]==2)print(da[i]);
	}
	Flush();
	return 0;
}
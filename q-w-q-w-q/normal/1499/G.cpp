#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353,up=400005;
int n1,n2,m,cnt,q,val,ans,x,y,z;
int f[up],to[up][2],v[up][2];
int st[up],k;
bool op[up],od[up];
inline int add(int x,int y){return x+y<mod?x+y:x+y-mod;}
inline int sub(int x,int y){return x<y?x+mod-y:x-y;}
inline int find(int x){
	if(x==f[x]) return x;
	int y=f[x],z=find(y);
	op[x]^=op[y];
	return f[x]=z;
}
inline void link(int x,int y){
	cnt++,val=(val<<1)%mod,f[cnt]=cnt;
	if(od[x]<od[y]) swap(x,y);
	if(!od[x]){
		od[x]^=1,od[y]^=1;
		to[x][0]=y,to[y][0]=x;
		to[x][1]=to[y][1]=cnt;
		v[cnt][0]=val;
		return;
	}
	if(!od[y]){
		od[x]^=1,od[y]^=1;
		int z=to[x][0],w=to[x][1],t=find(w);
		to[z][0]=y,to[y][0]=z,to[y][1]=cnt;
		f[cnt]=t,op[cnt]=op[w]^1,v[t][op[cnt]]=add(v[t][op[cnt]],val);
		if(op[cnt]) ans=add(ans,val);
		return;
	}
	od[x]^=1,od[y]^=1;
	if(to[x][0]==y){
		int w=to[x][1],t=find(w);
		f[cnt]=t,op[cnt]=op[w]^1,v[t][op[cnt]]=add(v[t][op[cnt]],val);
		if(op[cnt]) ans=add(ans,val);
		return;
	}
	int a=to[x][0],b=to[y][0];
	to[a][0]=b,to[b][0]=a;
	int w1=to[x][1],t1=find(w1),w2=to[y][1],t2=find(w2);
	f[cnt]=t1,op[cnt]=op[w1]^1,v[t1][op[cnt]]=add(v[t1][op[cnt]],val);
	if(op[cnt]) ans=add(ans,val);
	f[t2]=t1,op[t2]=op[w1]^op[w2];
	v[t1][0]=add(v[t1][0],v[t2][op[t2]]),v[t1][1]=add(v[t1][1],v[t2][1^op[t2]]);
	if(op[t2]) ans=add(ans,v[t2][0]),ans=sub(ans,v[t2][1]);
}
int main(){
	cin>>n1>>n2>>m;
	for(val=1;cnt<m;){
		scanf("%d%d",&x,&y);
		link(x,y+n1);
	}
	cin>>q;
	while(q--){
		scanf("%d",&z);
		if(z&1){
			scanf("%d%d",&x,&y);
			link(x,y+n1);
			printf("%d\n",ans);
			fflush(stdout);
		}
		else{
			k=0;
			for(int i=1;i<=cnt;i++){
				find(i);
				if(op[i]) st[++k]=i;
			}
			printf("%d",k);
			for(int i=1;i<=k;i++) printf(" %d",st[i]);
			putchar('\n');
			fflush(stdout);
		}
	}
}
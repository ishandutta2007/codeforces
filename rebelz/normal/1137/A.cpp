#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int ansx[1005],ansy[1005],a[1005][1005],sxa[1005][1005],sxb[1005][1005],sya[1005][1005],syb[1005][1005];
map<int,int> mp[1005];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!mp[i].count(a[i][j])) mp[i][a[i][j]]=1;
	for(int i=1;i<=n;i++){
		int num=0;
		for(auto v:mp[i]) mp[i][v.first]=++num;
		for(int j=1;j<=m;j++) sxa[i][j]=mp[i][a[i][j]],sxb[i][j]=num-mp[i][a[i][j]]+1;
		ansx[i]=num;
	}
	for(int i=1;i<=n;i++) mp[i].clear();
	for(int j=1;j<=m;j++) for(int i=1;i<=n;i++) if(!mp[j].count(a[i][j])) mp[j][a[i][j]]=1;
	for(int j=1;j<=m;j++){
		int num=0;
		for(auto v:mp[j]) mp[j][v.first]=++num;
		for(int i=1;i<=n;i++) sya[i][j]=mp[j][a[i][j]],syb[i][j]=num-mp[j][a[i][j]]+1;
		ansy[j]=num;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<sxa[i][j]<<' ';
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<sxb[i][j]<<' ';
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<sya[i][j]<<' ';
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<syb[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int tmp=max(ansx[i],ansy[j]);
			tmp=max(tmp,max(max(max(sxa[i][j],sya[i][j]),sxb[i][j]+sya[i][j]-1),max(sxa[i][j]+syb[i][j]-1,max(sxb[i][j],syb[i][j]))));
			printf("%d ",tmp);
		}
		printf("\n");
	}
	return 0;
}
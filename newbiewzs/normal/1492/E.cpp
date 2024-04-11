#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int N=2.5e5+5;
int n,m,x,b[10],head;
vector<int>a[N];
int st[N],top;
void out(){
	if(!top){
		cout<<"NO";
		exit(0);
	}
	puts("Yes");
	for(int i=1;i<=top;i++){
		printf("%d ",st[i]);
	}
	exit(0);
}
int vis[N],flag,san,si;
bool check(int u){
	for(int i=2;i<=n;i++){
		for(int k=1;k<=m;k++){
			if(a[i][k]!=a[1][k]){
				vis[i]++;
			}
		}
	}
	bool bj=0;
	for(int i=2;i<=n;i++){
		if(vis[i]>2)bj=1;
		if(vis[i]>4 and u)flag=1;
		if(vis[i]==3 and u)san=i;
		if(vis[i]==4 and u)si=i;
		if(vis[i]==3 and !u)san=i;
		vis[i]=0;
	}
	return (bj^1);
}
int ls[5],qs[5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		a[i].push_back(0);
		for(int k=1;k<=m;k++){
			scanf("%d",&x);
			a[i].push_back(x);
		}
	}
	if(check(1)){
		for(int k=1;k<=m;k++)st[++top]=a[1][k];
		flag=1;
	}
	if(flag){
		out();
	}
	if(san and !si){
		for(int i=1;i<=m;i++){
			if(a[1][i]!=a[san][i])b[++head]=i;
		}
		for(int i=1;i<=head;i++){
			int pos=b[i];
			int pre=a[1][pos];
			a[1][pos]=a[san][pos];
			bool bj=0;int jl=0;int temi,temj,aa;
			for(int k=2;k<=n;k++){
				int js=0;
				for(int j=1;j<=m;j++){
					if(a[k][j]!=a[1][j]){
						if(js<3 and jl<3){
							ls[++js]=k;
							qs[js]=j;
						}
					}
				}
				jl=max(js,jl);
			}
			if(jl<=2){
				for(int k=1;k<=m;k++)st[++top]=a[1][k];
				flag=1;
				break;
			}
			for(int j=1;j<=3;j++){
				a[1][pos]=a[san][pos];
				temi=ls[j];temj=qs[j];
				int aa=a[1][temj];
				a[1][temj]=a[temi][temj];
				if(check(0)){
					for(int k=1;k<=m;k++)st[++top]=a[1][k];
					flag=1;
					break;
				}
				a[1][pos]=pre;
				a[1][temj]=aa;
			}
			if(flag)break;
		}
	}
	if(si and !flag){
		for(int i=1;i<=m;i++){
			if(a[1][i]!=a[si][i])b[++head]=i;
		}
		for(int i=1;i<=head;i++){
			for(int k=i+1;k<=head;k++){
				int pos1=b[i];
				int pos2=b[k];
				int pre1=a[1][pos1];
				int pre2=a[1][pos2];
				a[1][pos1]=a[si][pos1];
				a[1][pos2]=a[si][pos2];
				if(check(0)){
					for(int k=1;k<=m;k++)st[++top]=a[1][k];
					flag=1;
					break;
				}
				a[1][pos1]=pre1;
				a[1][pos2]=pre2;
				if(flag)break;
			}
			if(flag)break;
		}
	}
	out();
	return 0;
}
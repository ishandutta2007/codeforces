#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
const int N=2e5+55;
int n,m,u,v,w;
char c[2],d[2];
map<int,int>ma[N];
int ou,ji;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%s",c+1);
		if(c[1]=='+'){
			scanf("%d%d%s",&u,&v,d+1);
			if(ma[v][u] and ma[v][u]==d[1]-'a'+1){
				ou++;
			}
			if(ma[v][u]){
				ji++;
			}
			ma[u][v]=d[1]-'a'+1;
		}
		if(c[1]=='-'){
			scanf("%d%d",&u,&v);
			if(ma[v][u] and ma[v][u]==ma[u][v]){
				ou--;
			}
			if(ma[v][u]){
				ji--;
			}
			ma[u][v]=0;
		}
		if(c[1]=='?'){
			scanf("%d",&u);
			if(u&1){
				if(ji)puts("YES");
				else puts("NO");
			}
			else{
				if(ou)puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}
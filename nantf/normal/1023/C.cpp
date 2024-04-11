#include<bits/stdc++.h>
using namespace std;
const int maxn=200020;
int n,m,stk[maxn],top,with[maxn];
char str[maxn];
bool vis[maxn];
int main(){
	scanf("%d%d%s",&n,&m,str+1);
	for(int i=1;i<=n;i++)
		if(str[i]=='(') stk[++top]=i;
		else with[stk[top]]=i,with[i]=stk[top--];
	int cnt=(n-m)>>1;
	for(int i=1;i<=n;i++){
		if(!cnt) break;
		if(!vis[i]) vis[i]=vis[with[i]]=true,cnt--;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) putchar(str[i]);
}
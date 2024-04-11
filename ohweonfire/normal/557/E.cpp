#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
struct node{
	int cnt,sum,l,r;
	node* ch[2];
	node()
	{
		cnt=0;
		ch[0]=ch[1]=NULL;
	}
};
node* root=new node();
char s[maxn];
bool dp[maxn][maxn];
int k,len,l,i,j;
int dfs(node *cur)
{
	if(cur==NULL)return 0;
	return cur->sum=cur->cnt+dfs(cur->ch[0])+dfs(cur->ch[1]);
}
void kth(node *cur,int k)
{
	if(cur->cnt>=k)return;
	k-=cur->cnt;
	if(cur->ch[0]!=NULL)
	{
		if(cur->ch[0]->sum>=k)
		{
			putchar('a');
			kth(cur->ch[0],k);
			return ;
		}
		k-=cur->ch[0]->sum;
	}
	putchar('b');
	kth(cur->ch[1],k);
}
int main()
{
	scanf("%s%d",s,&k);
	len=strlen(s);
	for(l=0;l<len;l++)
		for(i=0,j=l;j<len;i++,j++)
			dp[i][j]=(s[i]==s[j])&&(i+2>=j-2||dp[i+2][j-2]);
	for(i=0;i<len;i++)
	{
		node* cur=root;
		for(j=i;j<len;j++)
		{
			node* &child=cur->ch[s[j]-'a'];
			if(child==NULL)child=new node();
			if(dp[i][j])child->cnt++;
			cur=child;
		}
	}
	dfs(root);
	kth(root,k);
	return 0;
}
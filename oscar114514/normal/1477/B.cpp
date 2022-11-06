#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r,cnt,lazy;//count of '1'
	node *lson,*rson;
	inline void upd(){cnt=lson->cnt+rson->cnt;}
	inline void fa_lazy(){if(lazy!=-1){lson->mark(lazy);rson->mark(lazy);lazy=-1;}}
	inline void mark(int ty){lazy=ty;if(ty)cnt=r-l+1;else cnt=0;}
}*root,pool[1111111];
int top;
char s[233333],f[233333];
node *build(int l,int r)
{
	node *tmp=&pool[top++];tmp->l=l;tmp->r=r;tmp->lazy=-1;
	if(l==r)
	{
		tmp->cnt=f[l]-'0';
	}
	else
	{
		int mid=(l+r)/2;
		tmp->lson=build(l,mid);
		tmp->rson=build(mid+1,r);
		tmp->upd();
	}
	return tmp;
}
void change(node *cur,int l,int r,int ty)
{
	if(cur->l==l&&cur->r==r)
	{
		cur->mark(ty);
		return;
	}
	cur->fa_lazy();
	if(cur->lson->r>=r)change(cur->lson,l,r,ty);
	else if(cur->rson->l<=l)change(cur->rson,l,r,ty);
	else change(cur->lson,l,cur->lson->r,ty),change(cur->rson,cur->rson->l,r,ty);
	cur->upd();
}
int query(node *cur,int l,int r)
{
	if(cur->l==l&&cur->r==r)
	{
		return cur->cnt;
	}
	cur->fa_lazy();
	if(cur->lson->r>=r)return query(cur->lson,l,r);
	else if(cur->rson->l<=l)return query(cur->rson,l,r);
	else return query(cur->lson,l,cur->lson->r)+query(cur->rson,cur->rson->l,r);
}
int T,n,q;
int l[233333],r[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>q;
		cin>>(s+1)>>(f+1);
		for(int i=1;i<=q;i++)
		{
			cin>>l[i]>>r[i];
		}
		root=build(1,n);
		int ok=1;
		for(int i=q;i>=1;i--)
		{
			int c=query(root,l[i],r[i]);
//			cerr<<i<<' '<<l[i]<<' '<<r[i]<<' '<<c<<endl;
			int len=r[i]-l[i]+1;
			if(c*2<len)
			{
				change(root,l[i],r[i],0);
			}
			else if(c*2>len)
			{
				change(root,l[i],r[i],1);
			}
			else
				ok=0;
		}
		for(int i=1;i<=n;i++)
		{
			ok&=query(root,i,i)==s[i]-'0';
		}
		if(ok)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
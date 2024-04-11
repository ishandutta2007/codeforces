#include<bits/stdc++.h>
using namespace std;
int n,k;
int l1[233333],l2[233333],r1[233333],r2[233333];
pair<pair<int,int>,int> tr1[233333],tr2[233333];
unsigned long long w[233333],tt,v1[233333],v2[233333];
struct node
{
	int l,r;
	unsigned long long s;
	node *lson,*rson;
}*root,pool[5555555];
int top;
void init()
{
	top=0;
	memset(pool,0,sizeof(pool));
	root=&pool[top++];
	root->l=1;root->r=1e9;
}
void change(node *cur,int pos,unsigned long long w)
{
//	cerr<<"change "<<cur->l<<' '<<cur->r<<' '<<pos<<' '<<w<<' '<<cur->s<<endl;
	cur->s^=w;
	if(cur->l==cur->r)
	{
		return;
	}
	int mid=(cur->l+cur->r)/2;
	if(pos<=mid)
	{
		if(!cur->lson)
		{
			cur->lson=&pool[top++];
			cur->lson->l=cur->l;cur->lson->r=mid;
			cur->lson->s=0;
		}
		change(cur->lson,pos,w);
	}
	else
	{
		if(!cur->rson)
		{
			cur->rson=&pool[top++];
			cur->rson->l=mid+1;cur->rson->r=cur->r;
			cur->rson->s=0;
		}
		change(cur->rson,pos,w);
	}
}
unsigned long long query(node *cur,int l,int r)
{
	if(!cur||l>r)return 0;
//	cerr<<"query "<<l<<' '<<r<<' '<<cur->s<<endl;
	if(l<=cur->l&&cur->r<=r)return cur->s;
	int mid=(cur->l+cur->r)/2;
	unsigned long long ret=0;
	if(l<=mid)ret^=query(cur->lson,l,r);
	if(r> mid)ret^=query(cur->rson,l,r);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	tt=n^time(0);
	for(int i=1;i<=n;i++)
	{
		cin>>l1[i]>>r1[i]>>l2[i]>>r2[i];
		tr1[i]=make_pair(make_pair(l1[i],r1[i]),i);
		tr2[i]=make_pair(make_pair(l2[i],r2[i]),i);
		tt^=(((unsigned long long)l1[i]<<48)^((unsigned long long)r1[i]<<32)^((unsigned long long)l2[i]<<16)^r2[i]);
		tt^=tt<<26;
		tt^=tt>>47;
		tt^=tt<<19;
		w[i]=tt;
		w[i]=1<<i;
//		cerr<<w[i]<<' ';
	}
	init();
	sort(tr1+1,tr1+n+1);
	sort(tr2+1,tr2+n+1);
	tr1[n+1]=make_pair(make_pair(1e9+1,1e9+1),n+1);
	int pos=1;
	unsigned long long cur=0;
	for(int i=1;i<=n;i++)
	{
		if(pos==i)
		{
			cur=0;
			while(tr1[pos].first.first==tr1[i].first.first)cur^=w[tr1[pos].second],pos++;
		}
		v1[tr1[i].second]=cur;
	}
	pos=1;cur=0;
	for(int i=1;i<=n;i++)
	{
		if(pos==i)
		{
			cur=0;
			while(tr2[pos].first.first==tr2[i].first.first)cur^=w[tr2[pos].second],pos++;
		}
		v2[tr2[i].second]=cur;
	}
	pos=1;
	for(int i=1;i<=n;i++)
	{
		while(tr1[pos].first.first<tr1[i].first.first)change(root,tr1[pos].first.second,w[tr1[pos].second]),pos++;
		v1[tr1[i].second]^=query(root,tr1[i].first.first,1e9);
//		cerr<<tr1[i].second<<' '<<v1[tr1[i].second]<<endl;
	}
	init();
	pos=n;
	for(int i=n;i>=1;i--)
	{
		while(tr1[pos].first.first>tr1[i].first.first)change(root,tr1[pos].first.first,w[tr1[pos].second]),pos--;
		v1[tr1[i].second]^=query(root,1,tr1[i].first.second);
//		cerr<<tr1[i].second<<' '<<v1[tr1[i].second]<<endl;
	}
	init();
	tr2[n+1]=make_pair(make_pair(1e9+1,1e9+1),n+1);
	pos=1;
	for(int i=1;i<=n;i++)
	{
		while(tr2[pos].first.first<tr2[i].first.first)change(root,tr2[pos].first.second,w[tr2[pos].second]),pos++;
		v2[tr2[i].second]^=query(root,tr2[i].first.first,1e9);
//		cerr<<tr2[i].second<<' '<<v2[tr2[i].second]<<endl;
	}
	init();
	pos=n;
	for(int i=n;i>=1;i--)
	{
		while(tr2[pos].first.first>tr2[i].first.first)change(root,tr2[pos].first.first,w[tr2[pos].second]),pos--;
		v2[tr2[i].second]^=query(root,1,tr2[i].first.second);
//		cerr<<tr2[i].second<<' '<<v2[tr2[i].second]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
//		cerr<<i<<' '<<v1[i]<<' '<<v2[i]<<endl;
		if(v1[i]!=v2[i])return cout<<"NO"<<endl,0;
	}
	cout<<"YES"<<endl;
	return 0;
}
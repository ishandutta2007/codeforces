#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct segtree{
	struct segment{
		int l,r,sum;
	};
	segment seg[524289];
	void init(int l,int r,int t)
	{
		seg[t].l=l;
		seg[t].r=r;
		seg[t].sum=0;
		if(l==r)return;
		int mid=l+r>>1;
		init(l,mid,t<<1);
		init(mid+1,r,(t<<1)|1);
	}
	void set(int l,int r,int t,int v)
	{
		if(l>r)return;
		if(seg[t].l==l&&seg[t].r==r)
		{
			seg[t].sum=v*(r-l+1);
			return;
		}
		int mid=seg[t].l+seg[t].r>>1;
		if(seg[t].sum==seg[t].r-seg[t].l+1)
		{
			seg[t<<1].sum=mid-seg[t].l+1;
			seg[t<<1|1].sum=seg[t].r-mid;
		}
		else if(seg[t].sum==0)
			seg[t<<1].sum=seg[t<<1|1].sum=0;
		if(r<=mid)set(l,r,t<<1,v);
		else if(l>mid)set(l,r,t<<1|1,v);
		else
		{
			set(l,mid,t<<1,v);
			set(mid+1,r,t<<1|1,v);
		}
		seg[t].sum=seg[t<<1].sum+seg[t<<1|1].sum;
	}
	int query(int l,int r,int t)
	{
		if(seg[t].l==l&&seg[t].r==r)return seg[t].sum;
		int mid=seg[t].l+seg[t].r>>1;
		if(seg[t].sum==seg[t].r-seg[t].l+1)
		{
			seg[t<<1].sum=mid-seg[t].l+1;
			seg[t<<1|1].sum=seg[t].r-mid;
		}
		else if(seg[t].sum==0)
			seg[t<<1].sum=seg[t<<1|1].sum=0;
		if(r<=mid)return query(l,r,t<<1);
		else if(l>mid)return query(l,r,t<<1|1);
		else return query(l,mid,t<<1)+query(mid+1,r,t<<1|1);
	}
}seg[26];
char s[maxn],ans[maxn];
int n,m,num[26],l,r;
int main()
{
#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=0;i<26;i++)seg[i].init(1,n,1);
	for(int i=1;i<=n;i++)seg[s[i]-'a'].set(i,i,1,1);
	int odd,mid,pos;
	while(m--)
	{
		scanf("%d%d",&l,&r);
		odd=0;
		for(int i=0;i<26;i++)
		{
			num[i]=seg[i].query(l,r,1);
			if(num[i]&1)odd++;
		}
		if(odd>1)continue;
		if(odd==1)mid=l+r>>1;
		pos=0;
		for(int i=0;i<26;i++)
		{
			seg[i].set(l,r,1,0);
			seg[i].set(l+pos,l+pos+(num[i]>>1)-1,1,1);
			seg[i].set(r-pos-(num[i]>>1)+1,r-pos,1,1);
			if(num[i]&1)seg[i].set(mid,mid,1,1);
			pos+=num[i]>>1;
		}
	}
	for(int i=1;i<=n;++i)for(int j=0;j<26;j++)
		if(seg[j].query(i,i,1)==1)
			ans[i]='a'+j;
	printf("%s\n",ans+1);
	return 0;
}
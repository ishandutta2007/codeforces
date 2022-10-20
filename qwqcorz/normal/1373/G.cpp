#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct segment
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node
	{
		int mx,sum;
		void update(int x){mx=sum+=x;}
		friend node operator +(node a,node b)
		{
			return (node){
				max(a.mx+b.sum,b.mx),
				a.sum+b.sum
			};
		}
	}t[N*4];
	void add(int w,int l,int r,int x,int y)
	{
		if (l==r) return t[w].update(y);
		if (x<=mid) add(ls,l,mid,x,y);
			   else add(rs,mid+1,r,x,y);
		t[w]=t[ls]+t[rs];
	}
	node query(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w];
		if (qr<=mid) return query(ls,l,mid,ql,qr);
		if (ql>mid) return query(rs,mid+1,r,ql,qr);
		return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
	}
	void build(int w,int l,int r)
	{
		if (l==r) return t[w]=(node){-1,-1},void();
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]+t[rs];
	}
	#undef mid
	#undef rs
	#undef ls
}t;
unordered_map<int,int>mp[N];
multiset<int>S;

signed main()
{
	int n=read(),k=read(),Q=read();
	t.build(1,1,n+n);
	while (Q--)
	{
		int x=read(),y=read();
		bool flag=mp[x][y]^=1;
		t.add(1,1,n+n,y+abs(x-k),flag?1:-1);
		if (flag) S.insert(y+abs(x-k));
			 else S.erase(S.find(y+abs(x-k)));
		if (S.empty())
		{
			puts("0");
			continue;
		}
		int pos=*S.rbegin();
		print(max(pos+t.query(1,1,n+n,1,pos).mx-n,0));
	}
	
	return 0;
}
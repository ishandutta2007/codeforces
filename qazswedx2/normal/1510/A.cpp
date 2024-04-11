#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int x,y;
};
char s[105],tans[5005][5005];
int n,a[105],st[105],tp,d[105],mp[1005];
pt f[105][105];
pt solve1(int l,int r)
{
//	printf("solve1:l=%d,r=%d\n",l,r); 
	pt ans;
	ans.x=ans.y=0;
	int fl=0;
	for(int i=l;i<=r;i++)
		if(s[i]=='|'&&d[i]==d[l]) fl=1;
	if(fl)
	{
		int las=l;
		for(int i=l;i<=r+1;i++)
		{
			if(i==r+1||s[i]=='|'&&d[i]==d[l])
			{
				pt q=solve1(las,i-1);
				las=i+1;
				ans.x+=q.x+1;
				ans.y=max(ans.y,q.y);
			}
		}
		ans.x--;
		ans.y+=6;
		return f[l][r]=ans;
	}
	int id=-1;
	if(s[l]=='(')
	{
		if(a[l]<r&&mp[s[a[l]+1]])
		{
			int nw=a[l]+1;
			while(nw<r&&mp[s[nw+1]]) nw++;
			id=nw;
		}
		else
		{
			pt p=solve1(l+1,a[l]-1);
			if(a[l]==r) return f[l][r]=p;
			pt q=solve1(a[l]+1,r);
			ans.x=max(p.x,q.x);
			ans.y=p.y+q.y+2;
			return f[l][r]=ans;
		}
	}
	else
	{
		for(int i=l;i<=r+1;i++)
		{
			if(i==r+1)
			{
				ans.x=3;
				ans.y=r-l+1+4;
				return f[l][r]=ans;
			}
			if(s[i]=='+'||s[i]=='?'||s[i]=='*'||s[i]=='(')
			{
				if(mp[s[i]])
				{
					int nw=i;
					while(nw<r&&mp[s[nw+1]]) nw++;
					id=nw;
				}
				else id=i-1;
				break;
			}
		}
	}
	int i=id;
	if(i==r&&i>=l+2&&s[l]>='A'&&s[l]<='Z'&&s[l+1]>='A'&&s[l+1]<='Z')
	{
		while(mp[s[i]]) i--;
		i--;
	}
	if(i!=r)
	{
		pt p=solve1(l,i);
		pt q=solve1(i+1,r);
		ans.x=max(p.x,q.x);
		ans.y=p.y+q.y+2;
		return f[l][r]=ans;
	}
	pt p=solve1(l,i-1);
	if(s[i]=='+') p.x+=2,p.y+=6;
	if(s[i]=='?') p.x+=3,p.y+=6;
	if(s[i]=='*') p.x+=5,p.y+=6;
	return f[l][r]=p;
}
#define F(x,y,c) tans[(x)+xl][(y)+yl]=c
void G(int xl,int xr,int yl,int yr)
{
	int x=xr-xl+1,y=yr-yl+1;
	F(0,0,'+');
	F(0,y-1,'+');
	F(x-1,0,'+');
	F(x-1,y-1,'+');
	for(int i=1;i<x-1;i++)
		F(i,0,'|'),F(i,y-1,'|');
	for(int i=1;i<y-1;i++)
		F(0,i,'-'),F(x-1,i,'-');
}
void solve2(int l,int r,int xl,int yl)
{
	int x=f[l][r].x,y=f[l][r].y;
	int xr=xl+x-1,yr=yl+y-1;
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			F(i,j,' ');
	int fl=0;
	for(int i=l;i<=r;i++)
		if(s[i]=='|'&&d[i]==d[l]) fl=1;
	if(fl)
	{
		int las=l,ct=0,lct=0;
		for(int i=l;i<=r+1;i++)
			if(i==r+1||s[i]=='|'&&d[i]==d[l])
			{
				if(ct) G(xl+lct+1,xl+ct+1,yl,yr);
				pt q=f[las][i-1];
				las=i+1;
				lct=ct;
				ct+=q.x+1;
			}
		las=l,ct=0;
		for(int i=l;i<=r+1;i++)
			if(i==r+1||s[i]=='|'&&d[i]==d[l])
			{
				solve2(las,i-1,xl+ct,yl+3);
				F(ct+1,y-2,'>');
				F(ct+1,2,'>');
				pt q=f[las][i-1];
				las=i+1;
				ct+=q.x+1;
			}
	/*	ct=0;
		las=l;
		for(int i=l;i<=r+1;i++)
			if(i==r+1||s[i]=='|'&&d[i]==d[l])
			{
				ct+=f[las][i-1].x+1;
				las=i+1;
			}*/
		return;
	}
	int id=-1;
	if(s[l]=='(')
	{
		if(a[l]<r&&mp[s[a[l]+1]])
		{
			int nw=a[l]+1;
			while(nw<r&&mp[s[nw+1]]) nw++;
			id=nw;
		}
		else
		{
			pt p=f[l+1][a[l]-1];
			solve2(l+1,a[l]-1,xl,yl);
			if(a[l]==r) return;
			solve2(a[l]+1,r,xl,yl+p.y+2);
			F(1,p.y,'-');
			F(1,p.y+1,'>');
			return;
		}
	}
	else
	{
		for(int i=l;i<=r+1;i++)
		{
			if(i==r+1)
			{
				F(0,0,'+'),F(1,0,'+'),F(2,0,'+');
				F(0,y-1,'+'),F(1,y-1,'+'),F(2,y-1,'+');
				int k=l;
				for(int j=1;j<y-1;j++)
				{
					F(0,j,'-');
					F(2,j,'-');
					if(j>=2&&j<y-2)
						F(1,j,s[k++]);
				}
				return;
			}
			if(s[i]=='+'||s[i]=='?'||s[i]=='*'||s[i]=='(')
			{
				if(mp[s[i]])
				{
					int nw=i;
					while(nw<r&&mp[s[nw+1]]) nw++;
					id=nw;
				}
				else id=i-1;
				break;
			}
		}
	}
	int i=id;
	if(i==r&&i>=l+2&&s[l]>='A'&&s[l]<='Z'&&s[l+1]>='A'&&s[l+1]<='Z')
	{
		while(mp[s[i]]) i--;
		i--;
	}
	if(i!=r)
	{
		pt p=f[l][i];
		solve2(l,i,xl,yl);
		solve2(i+1,r,xl,yl+p.y+2);
		F(1,p.y,'-');
		F(1,p.y+1,'>');
		return;
	}
//	pt p=f[l][i-1];
	if(s[i]=='+')
	{
		G(xl+1,xr,yl,yr);
		solve2(l,i-1,xl,yl+3);
		F(1,2,'>');
		F(1,y-2,'>');
		F(x-1,1,'<');
	}
	if(s[i]=='?')
	{
		G(xl+1,xl+4,yl,yr);
		solve2(l,i-1,xl+3,yl+3);
		F(1,y-2,'>');
		F(4,2,'>');
		F(4,y-2,'>');
	}
	if(s[i]=='*')
	{
		G(xl+1,xr,yl,yr);
		G(xl+1,xl+4,yl,yr);
		solve2(l,i-1,xl+3,yl+3);
		F(1,y-2,'>');
		F(4,2,'>');
		F(4,y-2,'>');
		F(x-1,1,'<');
	}
	return;
}
int main()
{
	mp['+']=1,mp['*']=1,mp['?']=1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=tp;
		if(s[i]=='(') st[++tp]=i;
		else if(s[i]==')')
		{
			a[st[tp]]=i;
			a[i]=st[tp];
			tp--;
			d[i]=tp;
		}
	}
	solve1(1,n);
	//for(int i=1;i<=n;i++)
	//	for(int j=1;j<=n;j++)
	//		if(f[i][j].x)
	//			printf("l=%d,r=%d,f=%d,%d\n",i,j,f[i][j].x,f[i][j].y);
	printf("%d %d\n",f[1][n].x,f[1][n].y+6);
	solve2(1,n,1,4);
	tans[2][1]='S',tans[2][2]='-',tans[2][3]='>';
	int y=f[1][n].y+4;
	tans[2][y]='-',tans[2][y+1]='>',tans[2][y+2]='F';
	for(int i=1;i<=f[1][n].x;i++)
	{
		for(int j=1;j<=f[1][n].y+6;j++)
			if(!tans[i][j]) printf(" ");
			else printf("%c",tans[i][j]);
		printf("\n");
	}
	return 0;
}
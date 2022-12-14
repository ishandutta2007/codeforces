#include<bits/stdc++.h>
using namespace std;
const int N=4e3+5;
const int inf=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int siz[N],id[N];
namespace Flow
{
	struct edge
	{
		int to,nxt,val;
	}e[N*3];
	int cur[N],head[N],cnte,n,S,T;
	int add_edge(int u,int v,int w)
	{
		e[++cnte].to=v;
		e[cnte].val=w;
		e[cnte].nxt=head[u];
		head[u]=cnte;
		return cnte;
	}
	int add(int u,int v,int w)
	{
		int ret=add_edge(u,v,w);
		add_edge(v,u,0);
		return ret;
	}
	int deep[N],q[N];
	bool bfs()
	{
		for (int i=0;i<=n;i++) deep[i]=0,cur[i]=head[i];
		int h=1,t=1;
		deep[q[1]=S]=1;
		while (h<=t)
		{
			int now=q[h++];
			for (int i=head[now];i;i=e[i].nxt)
			if (e[i].val)
			{
				int to=e[i].to;
				if (!deep[to]) deep[q[++t]=to]=deep[now]+1;
			}
		}
		return deep[T];
	}
	int dfs(int now,int flow)
	{
		if (!flow) return 0;
		if (now==T) return flow;
		int ret=0;
		for (int i=cur[now];i;cur[now]=i=e[i].nxt)
		if (e[i].val)
		{
			int to=e[i].to,val=e[i].val,tmp=0;
			if (deep[to]==deep[now]+1&&(tmp=dfs(to,min(flow,val))))
			flow-=tmp,e[i].val-=tmp,e[i^1].val+=tmp,ret+=tmp;
			if (!flow) return ret;
		}
		return ret;
	}
	int solve()
	{
		int ret=0;
		while (bfs()) ret+=dfs(S,inf);
		return ret;
	}
	void send(int _n,int _S,int _T)
	{
		for (int i=0;i<=_n;i++) head[i]=0;
		n=_n,S=_S,T=_T;
		cnte=1;
	}
}
vector<int>ans[N],t;

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n1=read(),n2=read(),m=read(),S=0,T=n1+n2+1,Min=m;
	Flow::send(T,S,T);
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		id[i]=Flow::add(u,v+n1,1);
		siz[u]++,siz[v+n1]++;
	}
	for (int i=1;i<=n1+n2;i++) Min=min(Min,siz[i]);
	for (int i=1;i<=n1;i++) t.push_back(Flow::add(S,i,siz[i]-Min));
	for (int i=n1+1;i<=n1+n2;i++) t.push_back(Flow::add(i,T,siz[i]-Min));
	for (int i=Min;i>=0;i--)
	{
		Flow::solve();
		for (int j=1;j<=m;j++) if (Flow::e[id[j]].val) ans[i].push_back(j);
		for (int j:t) Flow::e[j].val++;
	}
	for (int i=0;i<=Min;i++)
	{
		print(ans[i].size(),' ');
		for (int j:ans[i]) print(j,' ');
		puts("");
	}
	
	return 0;
}
//....................  ..                        .    . . ..   .                                          .........
//...................  ....,]]]]]]`.   . .         . .,@@@@@@`.. .                                          ........
//................... ,@@@@@@@@@@@@@@@@@@\].,]]]]]`,@@@@@@@@@@@. .                                          ........
//....................@^...[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`                                            .......
//...................,@`......\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`.                                          .......
//...................=@......../@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`.                                         .......
//...................=@....../@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.                                         .......
//...................=@....=@@@@@@/[[[[[@@@@@@@@@@@@@@@@@/`...[@@@@^                                         .......
//...................=@.../@@@/`...........\@@@@@@@@@@@`........,@@@.                                     . ........
//......,/@@@@@@@O\]`.@`.=@@@`...............\@@@@@@@@`...........@@^                                       ........
//....,@^........,/@@@@^,@@/..................,@@@@@@^............,@@.                                     .........
//....//......,/@[=OOOOO=@@....................,@@@@@...]O@@]......=@^                                     .........
//....@`....]@OO^.=OOO/@@@^.../@@@@@@@`.........=@@@@.=@@@@@@@@....=@^                                     .........
//...=@...,@OOO/.......=@@^.,@@@@@@@@@@@........=@@@@,@@@@@@@@@@...=@^                                    ..........
//...=@..=@`............\@^,@@@@@@@@@@@@@........@@@@=@@@@@@@@@@^..=@.                                 .............
//...=@.=@@OO@@]........@@@=@@@@@@@@@@@@@^......=@@@@O@@@@@@@@@@^..//.                                  ............
//...=@,@`.   .,\@`....=@\@@@@@@@@@@@@@@@^......O@@@@@@@@@@@@@@@..=@.  ......  .  . .......            .............
//...=@@/ ........\@`..=@.\@@@@@@@@@@@@@@^.....=@@@@@@@@@@@@@@@^./@`...,/@O[[...[[[O@@/.=/ .  ...... ...............
//....@@^   /@OOOO@@@\.=@  =@@@@@@@@@@@@@...../@@@@@@@@@@@@@@/]/@/...,@`...............[@@[[O@\`,[[@]...............
//....\@^  =@OOOOOOOO@\.@. OO@@@@@@@@@@/...,@@@@@@@@@@@@@@@@@@@@` .,@`.......,^...........,`...,\@`..,@.............
//....,@^ .=OOOOOOOOOO@\O^.\OOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/... ,@........=/..../@/[............\@...@`...........
//.....=@. =@OOOOOOOOOO@/@.,@OOOO@@@@@@@@@@@@@@@@@@@@@@@/[...    .@`...........,@`.................,@..=O...........
//......@\..\OOOOOOOOOO@^=@.,@OO@@@@@@@@@@@@@@@@@@@@@^         . .O......@O@^.,@....................=\..@*..........
//.......\@..\@OOOOOOOO@O.,@`..@@@@@@@@@@@@@@@@@@@@@@O    .     .,O......=@@`.=^.....................@..@@@]`.......
//........,@\..\@@OOOO@@^...\@@@@@@@@@@@@@@@@@@@@@@@@@.  ..,/@@@@@@..=@`......=O.........../^........@]@@O\*,O@`....
//..........,O@O]....,/@......@@@@@@@@@@@@@@@@@@@@@@@@^../@`*****=@@/@[....,[@`\@.......,@` .......,@/*********@\...
//..............,[\O@@@@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@.=O*******[[[[O@@O]`]]]/@`@@@O@@O[[[***[[[\@@`*********,O@^..
//.................**O@...../@@@@@@@@@@@@@@@@@@@@@@@@@@@`*****************,\@*****[[`**************************=@...
//................****,@@@@@/*,@@@@@@@@@@@@@@@@@@@@@@@@O*******************************************************O/*..
//...................************[[\OO@@@@@@O/[[[[[[[*,@@\]**************************************************,@@*...
//..............................**********************.***[[@@O]]`***************************************]]@@[**....
//..........................................................*****,[[[OOOOOOOOOOOOOO@@@@@@@@@@@@O@OOOOO[[[****.......
//................................................................................******************................
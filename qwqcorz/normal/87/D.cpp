#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;

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
struct edge
{
	int to,nxt,val;
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v,int w)
{
	e[++cnte].to=v;
	e[cnte].val=w;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int fa[N],siz[N],tot[N],deep[N];
int u[N],v[N],w[N],ans[N];
map<int,vector<int>>eid;
vector<int>to[N],p;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int now,int father)
{
	tot[now]=siz[find(now)];
	deep[now]=deep[father]+1;
	for (int t:to[now])
	{
		if (t==father) continue;
		dfs(t,now);
		tot[now]+=tot[t];
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		add_edge(u[i],v[i],w[i]);
		add_edge(v[i],u[i],w[i]);
		eid[w[i]].push_back(i);
	}
	for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for (auto tmp:eid)
	{
		#define x find(u[i])
		#define y find(v[i])
		for (int i:tmp.second)
			p.push_back(x),
			p.push_back(y),
			to[x].push_back(y),
			to[y].push_back(x);
		for (int i:p) if (!deep[i]) dfs(i,0);
		for (int i:tmp.second)
		{
			if (deep[x]>deep[y]) swap(u[i],v[i]);
			ans[i]=tot[y];
		}
		for (int i:tmp.second) siz[y]+=siz[x],fa[x]=y;
		for (int i:tmp.second) ans[i]=ans[i]*(siz[y]-ans[i]);
		for (int i:p) to[i].clear(),deep[i]=tot[i]=0;
		p.clear();
	}
	int mx=0,tot=0;
	for (int i=1;i<n;i++) mx=max(mx,ans[i]);
	print(mx*2,' ');
	for (int i=1;i<n;i++) if (mx==ans[i]) tot++;
	print(tot);
	for (int i=1;i<n;i++) if (mx==ans[i]) print(i,' ');
	
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
#include<bits/stdc++.h>
#define ll long long
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
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct SAM
{
	int siz,End;
	struct node
	{
		bool isclone;
		int len,link,tot;
		int to[26];
		void clear()
		{
			link=tot=len=isclone=0;
			memset(to,0,sizeof(to));
		}
	}a[N*2];
	SAM(){siz=End=1;}
	void insert(int c)
	{
		c-='a';
		int now=++siz,p=End;
		a[now].len=a[p].len+1;
		End=now;
		for (;p&&!a[p].to[c];p=a[p].link) a[p].to[c]=now;
		if (!p) return void(a[now].link=1);
		int q=a[p].to[c];
		if (a[p].len+1==a[q].len) a[now].link=q;
		else
		{
			a[++siz]=a[q];
			a[siz].isclone=1;
			a[siz].len=a[p].len+1;
			a[q].link=a[now].link=siz;
			for (;p&&a[p].to[c]==q;p=a[p].link) a[p].to[c]=siz;
		}
	}
	struct edge
	{
		int to,nxt;
	}e[N*2];
	int head[N*2],cnte;
	void add_edge(int u,int v)
	{
		e[++cnte].to=v;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
	void dfs(int now)
	{
		a[now].tot=!a[now].isclone;
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			dfs(to);
			a[now].tot+=a[to].tot;
		}
	}
	ll solve()
	{
		cnte=0;
		for (int i=1;i<=siz;i++) head[i]=0;
		for (int i=2;i<=siz;i++) add_edge(a[i].link,i);
		dfs(1);
		ll ret=0;
		for (int i=1;i<=siz;i++) ret+=1LL*(a[i].len-a[a[i].link].len)*a[i].tot*a[i].tot;
//		for (int i=1;i<=siz;i++)
//		{
//			print(a[i].len,' ');
//			print(a[i].link,' ');
//			print(a[i].tot,':');
//			for (int j=0;j<26;j++) if (a[i].to[j]) putchar(j+'a'),print(a[i].to[j],' ');
//			puts("");
//		}
		return ret;
	}
	void clear()
	{
		for (int i=1;i<=siz;i++) a[i].clear();
		siz=End=1;
	}
}s;
char a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		scanf("%s",a+1);
		int n=strlen(a+1);
		for (int i=1;i<=n;i++) s.insert(a[i]);
		print(s.solve());
		s.clear();
	}
	
	return 0;
}
//...................  ..                        .    . . ..   .                                          .........
//..................  ....,]]]]]]`.   . .         . .,@@@@@@`.. .                                          ........
//.................. ,@@@@@@@@@@@@@@@@@@\].,]]]]]`,@@@@@@@@@@@. .                                          ........
//...................@^...[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`                                            .......
//..................,@`......\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`.                                          .......
//..................=@......../@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`.                                         .......
//..................=@....../@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.                                         .......
//..................=@....=@@@@@@/[[[[[@@@@@@@@@@@@@@@@@/`...[@@@@^                                         .......
//..................=@.../@@@/`...........\@@@@@@@@@@@`........,@@@.                                     . ........
//.....,/@@@@@@@O\]`.@`.=@@@`...............\@@@@@@@@`...........@@^                                       ........
//...,@^........,/@@@@^,@@/..................,@@@@@@^............,@@.                                     .........
//...//......,/@[=OOOOO=@@....................,@@@@@...]O@@]......=@^                                     .........
//...@`....]@OO^.=OOO/@@@^.../@@@@@@@`.........=@@@@.=@@@@@@@@....=@^                                     .........
//..=@...,@OOO/.......=@@^.,@@@@@@@@@@@........=@@@@,@@@@@@@@@@...=@^                                    ..........
//..=@..=@`............\@^,@@@@@@@@@@@@@........@@@@=@@@@@@@@@@^..=@.                                 .............
//..=@.=@@OO@@]........@@@=@@@@@@@@@@@@@^......=@@@@O@@@@@@@@@@^..//.                                  ............
//..=@,@`.   .,\@`....=@\@@@@@@@@@@@@@@@^......O@@@@@@@@@@@@@@@..=@.  ......  .  . .......            .............
//..=@@/ ........\@`..=@.\@@@@@@@@@@@@@@^.....=@@@@@@@@@@@@@@@^./@`...,/@O[[...[[[O@@/.=/ .  ...... ...............
//...@@^   /@OOOO@@@\.=@  =@@@@@@@@@@@@@...../@@@@@@@@@@@@@@/]/@/...,@`...............[@@[[O@\`,[[@]...............
//...\@^  =@OOOOOOOO@\.@. OO@@@@@@@@@@/...,@@@@@@@@@@@@@@@@@@@@` .,@`.......,^...........,`...,\@`..,@.............
//...,@^ .=OOOOOOOOOO@\O^.\OOOO@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/... ,@........=/..../@/[............\@...@`...........
//....=@. =@OOOOOOOOOO@/@.,@OOOO@@@@@@@@@@@@@@@@@@@@@@@/[...    .@`...........,@`.................,@..=O...........
//.....@\..\OOOOOOOOOO@^=@.,@OO@@@@@@@@@@@@@@@@@@@@@^         . .O......@O@^.,@....................=\..@*..........
//......\@..\@OOOOOOOO@O.,@`..@@@@@@@@@@@@@@@@@@@@@@O    .     .,O......=@@`.=^.....................@..@@@]`.......
//.......,@\..\@@OOOO@@^...\@@@@@@@@@@@@@@@@@@@@@@@@@.  ..,/@@@@@@..=@`......=O.........../^........@]@@O\*,O@`....
//.........,O@O]....,/@......@@@@@@@@@@@@@@@@@@@@@@@@^../@`*****=@@/@[....,[@`\@.......,@` .......,@/*********@\...
//.............,[\O@@@@@@@O@@@@@@@@@@@@@@@@@@@@@@@@@@@.=O*******[[[[O@@O]`]]]/@`@@@O@@O[[[***[[[\@@`*********,O@^..
//................**O@...../@@@@@@@@@@@@@@@@@@@@@@@@@@@`*****************,\@*****[[`**************************=@...
//...............****,@@@@@/*,@@@@@@@@@@@@@@@@@@@@@@@@O*******************************************************O/*..
//..................************[[\OO@@@@@@O/[[[[[[[*,@@\]**************************************************,@@*...
//.............................**********************.***[[@@O]]`***************************************]]@@[**....
//.........................................................*****,[[[OOOOOOOOOOOOOO@@@@@@@@@@@@O@OOOOO[[[****.......
//...............................................................................******************................
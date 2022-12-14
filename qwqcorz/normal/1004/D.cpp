#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=1e6+5;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
void error(){puts("-1"),exit(0);}
pair<int,int>q[N];
int dis[N],tot[N],tt,a[N];
int id(int n,int m,int x,int y){return (x-1)*m+y;}
void check(int n,int m,int x,int y)
{
	if (x>n||y>m) return;
	for (int i=1;i<=tt;i++) dis[i]=-1,tot[i]=0;
	dis[id(n,m,x,y)]=0;
	int h=1,t=1;
	q[1]=mk(x,y);
	while (h<=t)
	{
		int x=q[h].fi,y=q[h++].se;
		for (int i=0;i<4;i++)
		if (1<=x+dx[i]&&x+dx[i]<=n)
		if (1<=y+dy[i]&&y+dy[i]<=m)
		if (!~dis[id(n,m,x+dx[i],y+dy[i])])
		{
			dis[id(n,m,x+dx[i],y+dy[i])]=dis[id(n,m,x,y)]+1;
			q[++t]=mk(x+dx[i],y+dy[i]);
		}
	}
	for (int i=1;i<=tt;i++) tot[dis[i]]++;
	for (int i=1;i<=tt;i++) if (tot[i]!=a[i]) return;
	print(n,' '),print(m);
	print(x,' '),print(y);
	exit(0);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	tt=read();
	for (int i=1;i<=tt;i++) a[read()]++;
	int x=0,mx=0;
	for (int i=0;i<=tt;i++) if (a[i]) mx=i;
	for (int i=0;i<=tt;i++)
	{
		if (a[i]>i*4+!i) error();
		if (a[i]<i*4+!i)
		{
			x=i;
			break;
		}
	}
	if (x==0) error();
	for (int i=1;i<=tt;i++) if (tt%i==0) check(i,tt/i,x,i+tt/i-x-mx);
	puts("-1");
	
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
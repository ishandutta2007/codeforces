#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int p=1919810111;

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
char s[N],t[N];
int dp[N],mx[N],h1[N],h2[N],can[N];
bool check(int x,int m)
{
	for (int i=1;i<=m;i++) if (s[x+i-1]!='?'&&s[x+i-1]!=t[i]) return 0;
	return 1;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	for (int i=1;i<=m;i++) h1[i]=(h1[i-1]*27LL+t[i]-'a'+1)%p;
	for (int i=m,pw=1;i>=1;i--,pw=pw*27LL%p) h2[i]=(h2[i+1]+pw*(t[i]-'a'+1LL))%p;
	for (int i=1;i<=m;i++) can[i]=h1[i]==h2[m-i+1];
	for (int i=1;i<=n-m+1;i++)
	if (check(i,m))
	{
		dp[i]=mx[max(i-m,0)]+1;
		for (int j=max(i-m+1,1);j<i;j++)
		if (dp[j]>=0&&can[j+m-i])
		dp[i]=max(dp[i],dp[j]+1);
		mx[i]=max(mx[i-1],dp[i]);
	}
	else mx[i]=mx[i-1],dp[i]=-1;
	print(mx[max(n-m+1,0)]);
	
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
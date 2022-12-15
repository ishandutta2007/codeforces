#include<cstdio>
#include<cstring>

char s[101],a[2][13];
int f[26],wei1,wei2,cha;
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

bool check(int x,int x1,int y1)
{
	if (x==strlen(s)-1) return 1;
	for (int i=0; i<8; i++)
	{
		int xx=x1+dir[i][0],yy=y1+dir[i][1];
		if (xx>=0&&yy>=0&&xx<2&&yy<13&&a[xx][yy]==s[x+1]) 
			if (check(x+1,xx,yy)) return 1;
	}
	return 0;
}

int main()
{
	scanf("%s",&s);
	memset(f,255,sizeof(f));
	for (int i=0; i<strlen(s); i++)
		if (f[s[i]-'A']==-1) f[s[i]-'A']=i;
		else wei1=f[s[i]-'A'],wei2=i,cha=i-f[s[i]-'A']-1;
	if (12-(cha/2)-wei1>=0)
	{
		if (!(cha&1))
		{
			for (int i=12-(cha/2)-wei1; i<13; i++) a[0][i]=s[i-(12-(cha/2)-wei1)];
			for (int i=12; i>12-cha/2; i--) a[1][i]=s[cha/2+wei1+1+(12-i)];
			for (int i=12-cha/2; i>=0; i--) a[1][i]=s[wei2+(12-cha/2-i)+1];
			for (int i=0; i<12-cha/2-wei1; i++) a[0][i]=s[26+i-(11-cha/2-wei1)];
		}
		else
		{
			for (int i=12-(cha/2)-wei1; i<13; i++) a[0][i]=s[i-(12-(cha/2)-wei1)];
			for (int i=12; i>=12-cha/2; i--) a[1][i]=s[cha/2+wei1+1+(12-i)];
			for (int i=11-cha/2; i>=0; i--) a[1][i]=s[wei2+(11-cha/2-i)+1];
			for (int i=0; i<12-cha/2-wei1; i++) a[0][i]=s[26+i-(11-cha/2-wei1)];
		}
		if (check(0,0,12-(cha/2)-wei1))
		{
			for (int i=0; i<2; i++)
			{
				for (int j=0; j<=12; j++) putchar(a[i][j]);
				printf("\n");
			}
		}
		else printf("Impossible");
	}
	else
	{
		if (!(cha&1))
		{
			for (int i=wei1+cha/2-13; i>=0; i--) a[1][i]=s[(wei1+cha/2-13)-i];
			for (int i=0; i<13; i++) a[0][i]=s[i-(12-(cha/2)-wei1)];
			for (int i=12; i>12-cha/2; i--) a[1][i]=s[cha/2+wei1+1+(12-i)];
			for (int i=12-cha/2; i>wei1+cha/2-13; i--) a[1][i]=s[wei2+(12-cha/2-i)+1];
			for (int i=0; i<12-cha/2-wei1; i++) a[0][i]=s[26+i-(11-cha/2-wei1)];
		}
		else
		{
			for (int i=wei1+cha/2-13; i>=0; i--) a[1][i]=s[(wei1+cha/2-13)-i];
			for (int i=0; i<13; i++) a[0][i]=s[i-(12-(cha/2)-wei1)];
			for (int i=12; i>=12-cha/2; i--) a[1][i]=s[cha/2+wei1+1+(12-i)];
			for (int i=11-cha/2; i>wei1+cha/2-13; i--) a[1][i]=s[wei2+(11-cha/2-i)+1];
			for (int i=0; i<12-cha/2-wei1; i++) a[0][i]=s[26+i-(11-cha/2-wei1)];
		}
		if (check(0,1,wei1+cha/2-13))
		{
			for (int i=0; i<2; i++)
			{
				for (int j=0; j<=12; j++) putchar(a[i][j]);
				printf("\n");
			}
		}
		else printf("Impossible");
	}
	return 0;
}
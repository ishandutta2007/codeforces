#include<bits/stdc++.h>
using namespace std;
struct FastIO
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(long long& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
	{
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
			while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1;
        }
        return x=(f?-x:x),*this;
    }
}read;
void file()
{
	#ifndef ONLINE_JUDGE
	freopen("a.txt","r",stdin);
	#endif
}
#define sz 40
char ch[sz],ans[sz];
bool isdigit(char x){return x>='0'&&x<='9';}
bool judge()
{
	if (ch[0]=='R'&&isdigit(ch[1]))
	{
		int i;
		for (i=1;isdigit(ch[i]);i++);
		if (ch[i]=='C')
		{
			return 1;
		}
		return 0;
	}
	return 0;
}
int main()
{
	int n,i,j,k,x,y,z;
	read>>n;
	while (n--)
	{
		x=0;y=0;z=0;memset(ans,0,sizeof(ans));memset(ch,0,sizeof(ch));
		cin>>ch;
		if (judge())
		{
			for (i=1;isdigit(ch[i]);y=y*10+ch[i]-48,i++);
			for (i++;isdigit(ch[i]);x=x*10+ch[i]-48,i++);
			while (x) 
			{
				i=x%26;
				if (!i) ans[z]='Z',x-=26;
				else ans[z]=i+'A'-1;
//				ans[z]=(x+25)%26+'A';
				x/=26;z++;
			}
			while (z--) putchar(ans[z]);
			cout<<y<<'\n';
		}
		else
		{
			for (i=0;!isdigit(ch[i]);i++) x=x*26+ch[i]-'A'+1;
			for (;isdigit(ch[i]);i++) y=y*10+ch[i]-48;
			printf("R%dC%d\n",y,x);
		}
	}
}
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
#define sz 111
char ch[sz];
#define out {puts("NO");break;}
#define on {l++;r--;continue;}
int main()
{
	int T,n;
	read>>T;
	while (T--)
	{
		read>>n;
		cin>>ch;
		int l=0,r=n-1;
		while (l<r)
		{
			char a=ch[l],b=ch[r];
			if (a==b) on
			if (b=='a'||b=='z') swap(a,b);
			if (a=='a')
			{
				if (b!='c') out
				on
			} 
			else if (a=='z')
			{
				if (b!='x') out
				on
			}
			else if (abs(a-b)==1) out
			else if (abs(a-b)==2) on 
			else out
		}
		if (l>=r) puts("YES");
		memset(ch,'\0',sizeof(ch));
	}
}
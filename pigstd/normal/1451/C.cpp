#include<bits/stdc++.h>
using namespace std;

const int M=1e6+10;
int T,n,k;int t1[30],t2[30];
char s1[M],s2[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	T=read();
	while(T--)
	{
		n=read(),k=read();
		cin>>s1>>s2;int p=1;
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		for (int i=1;i<=n;i++)t1[s1[i-1]-'a'+1]++;
		for (int i=1;i<=n;i++)t2[s2[i-1]-'a'+1]++;
		for (int i=1;i<=25;i++)
		{
			int c=t1[i]-t2[i];
			if (c<0||c%k!=0){p=0;break;}
			t1[i+1]+=c;
		}
		if (p)puts("Yes");
		else puts("No");
	}
	return 0;
}
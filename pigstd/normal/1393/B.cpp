#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10; 
int n,a[M],q;
int _2=0,_4=0,_8=0,_6=0;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		a[x]++;
		if (a[x]==2)_2++;
		if (a[x]==4)_4++,_2--;
		if (a[x]==6)_6++,_4--;
		if (a[x]==8)_8++,_6--;
	}
	q=read();
	while(q--)
	{
		char ch;cin>>ch;
		int x=read();
		if (ch=='+')
		{
			a[x]++;
			if (a[x]==2)_2++;
			if (a[x]==4)_4++,_2--;
			if (a[x]==6)_6++,_4--;
			if (a[x]==8)_8++,_6--;
		}
		else
		{
			if (a[x]==2)_2--;
			if (a[x]==4)_4--,_2++;
			if (a[x]==6)_6--,_4++;
			if (a[x]==8)_8--,_6++;
			a[x]--;
		}
		if ((_4>=1&&_2>=2||
			_4>=2||
			_6>=1&&(_4||_2)||
			_6>=2||_8))puts("YES");
		else puts("NO");
	}
	return 0;
}
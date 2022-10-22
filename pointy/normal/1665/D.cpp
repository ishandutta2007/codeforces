#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

void work()
{
	int ans=0;
	for (int k=0;k<30;k++)
	{
		printf("? %d %d\n",(1<<k)-ans,-ans+(1<<k)+(1<<(k+1)));
		fflush(stdout);
		int x=read();
		if (x==(1<<(k+1))) 
		{
			ans+=(1<<(k));
		} 
	} 
	printf("! %d\n",ans);
	fflush(stdout);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}
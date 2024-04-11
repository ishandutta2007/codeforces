#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int B=300;

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
int n,d,x,a[N],b[N];
int getNextX() {
    x = (x * 37LL + 10007) % 1000000007;
    return x;
}
void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
int na[N],ans[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	n=read(),d=read(),x=read();
	initAB();
	vector<int>c;
	for (int i=0;i<n;i++) if (b[i]) c.push_back(i);
	for (int i=0;i<n;i++) na[a[i]]=i;
	for (int i=max(n-B,1);i<=n;i++)
	for (int j:c) if (na[i]+j<n) ans[na[i]+j]=i;
	for (int i=0;i<n;i++) if (!ans[i])
	{
		for (int j:c)
		if (j<=i) ans[i]=max(ans[i],a[i-j]);
			 else break;
	}
	for (int i=0;i<n;i++) print(ans[i]);
	
	return 0;
}
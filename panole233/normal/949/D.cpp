#include<cstdio>
#include<cstring>

int n,d,b,a[100001],w[100001],l,r,mid,ans,t,c,y,mi;

int getmin(int a,int b) {return a<b?a:b;}
int getabs(int x) {return x<0?(-x):x;}

bool check(int x)
{
	for (int i=1; i<=n; i++) w[i]=a[i];
	y=1;
    for (int i=x+1; i<=n-x; i++)
    {
        t=getmin(i,n-i+1); c=0;
        while (c!=b)
        {
            while (y<=n&&((1ll*t*d<getabs(i-y)&&y<i)||(!w[y]))) y++;
            if (1ll*t*d<getabs(i-y)||(!w[y])) return 0;
            mi=getmin(b-c,w[y]); c+=mi; w[y]-=mi;
        }
    }
    return 1;
}

int main()
{
    scanf("%d%d%d",&n,&d,&b);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	l=0; r=(n>>1); ans=0;
    while (l<=r)
    {
    	mid=(l+r)>>1;
    	if (check(mid)) r=mid-1,ans=mid; else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
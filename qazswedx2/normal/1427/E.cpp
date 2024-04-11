#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
ll a[105];
int n,bt,c[105],p2,ct;
ll b[1000005];
char buf[10000005];
set<ll> st;
void ins(ll x)
{
//	printf("ins:x=%lld\n",x);
	for(int i=62;i>=0;i--)
		if(x&(1ll<<i))
		{
			if(!a[i])
			{
				a[i]=x;
				return;
			}
			else
			{
				if(st.find(x^a[i])==st.end())
				{
					sprintf(buf+p2,"%lld ^ %lld\n",a[i],x);
					while(buf[p2]) p2++;
					ct++;
					b[++bt]=x^a[i];
					st.insert(x^a[i]);
				}
				x^=a[i];
			}
		}
//	printf("error\n");
	return;
}
bool check(ll x)
{
	for(int i=62;i>=0;i--)
		if(x&(1ll<<i))
		{
			if(!a[i])
				return 1;
			else x^=a[i];
		}
	return 0;
}
int main()
{
	srand(time(0));
	scanf("%d",&n);
	b[++bt]=n;
	st.insert(n);
	for(int i=1;;i++)
	{
		//printf("i=%d\n",i);
		ll x=b[rand()%bt+1],y=b[rand()%bt+1],fl=0,nw;
		if(!fl) nw=x+y;
		else nw=x^y;
		if(st.find(nw)!=st.end()||nw>1e18||!nw)
		{
			i--;
			continue;
		}
		if(check(nw)||rand()%1000==0)
		{
			sprintf(buf+p2,"%lld %c %lld\n",x,fl?'^':'+',y);
			while(buf[p2]) p2++;
			ct++;
			b[++bt]=nw;
			st.insert(nw);
			if(check(nw)) ins(nw);
			if(a[0])
			{
				printf("%d\n",ct);
				printf("%s",buf);
				return 0;
			}
			continue;
		}
		i--;
	}
	return 0;
}
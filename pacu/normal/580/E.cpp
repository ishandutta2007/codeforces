#include <cstdio>
using namespace std;
#define MOD 1000000007
#define B 10
#define SEG (1<<17)

int chash[100001];

int pw[100001];

int seg[2*SEG],l[2*SEG],r[2*SEG],up[2*SEG];

int A[100000];
int N,M,K;

void getPowers()
{
	pw[0] = 1;
	for(int i=1;i<=100000;i++)
		pw[i] = (pw[i-1]*((long long)B))%MOD;
	chash[0] = 0;
	for(int i=1;i<=100000;i++)
		chash[i] = (chash[i-1]+pw[i-1])%MOD;
}

void pull(int i)
{
	seg[i] = (seg[2*i] + pw[r[2*i]+1-l[2*i]]*((long long)seg[2*i+1]))%MOD;
}

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		if(i-SEG < N) seg[i] = A[i-SEG];
		l[i] = r[i] = i-SEG;
		up[i] = -1;
	}
	for(int i=SEG-1;i>0;i--)
	{
		pull(i);
		l[i] = l[2*i], r[i] = r[2*i+1];
		up[i] = -1;
	}
}

void push(int i)
{
	if(up[i] != -1)
	{
		seg[i] = (up[i]*((long long)chash[r[i]+1-l[i]]))%MOD;
		if(i < SEG)
			up[2*i] = up[i], up[2*i+1] = up[i];
		up[i] = -1;
	}
}

int low,high,c,ans;
void getHash(int i)
{
	push(i);
	if((l[i]>high)||(r[i]<low)) return;
	if((l[i]>=low)&&(r[i]<=high))
	{
		push(i);
		ans = (ans + pw[l[i]-low]*((long long)seg[i]))%MOD;
		return;
	}
	getHash(2*i);
	getHash(2*i+1);
}

void update(int i)
{
	push(i);
	if((l[i]>high)||(r[i]<low)) return;
	if((l[i]>=low)&&(r[i]<=high))
	{
		up[i] = c;
		push(i);
		return;
	}
	update(2*i);
	update(2*i+1);
	pull(i);
}

char s[100001];

int main()
{
	scanf("%d %d %d",&N,&M,&K);
	int Q = M+K;
	scanf("%s",s);
	for(int i=0;i<N;i++)
		A[i] = (s[i]-'0');
	getPowers();
	init();
	int tp,l,r,d;
	int h1;
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d %d %d",&tp,&l,&r,&d);
		l--,r--;
		if(tp == 1)
		{
			low = l, high = r, c = d;
			update(1);
		}
		else
		{
			low = l, high = r-d;
			ans = 0;
			getHash(1);
			h1 = ans;

			low = l+d, high = r;
			ans = 0;
			getHash(1);
			if(ans == h1) printf("YES\n");
			else printf("NO\n");
		}
	}
}
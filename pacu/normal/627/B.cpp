#include <iostream>
using namespace std;
#define SEG (1<<18)

long long a,b;

long long sega[2*SEG],segb[2*SEG],l[2*SEG],r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		sega[i] = segb[i] = 0;
		l[i] =r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		sega[i] = segb[i] = 0;
		l[i] = l[2*i], r[i] = r[2*i+1];
	}
}

void update(int i,int v)
{
	i += SEG;
	sega[i] += v;
	sega[i] = min(sega[i],a);
	segb[i] += v;
	segb[i] = min(segb[i],b);
	for(i/=2;i>0;i/=2)
	{
		sega[i] = sega[2*i]+sega[2*i+1];
		segb[i] = segb[2*i]+segb[2*i+1];
	}
}

int low,high;
long long getSuma(int i)
{
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return sega[i];
	return getSuma(2*i)+getSuma(2*i+1);
}
long long getSumb(int i)
{
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return segb[i];
	return getSumb(2*i)+getSumb(2*i+1);
}

int main()
{
	ios::sync_with_stdio(0);
	int N,K,Q;
	int tp,d,v,p;
	cin >> N >> K >> a >> b >> Q;
	init();
	for(int i=0;i<Q;i++)
	{
		cin >> tp;
		if(tp==1)
		{
			cin >> d >> v;
			update(d-1,v);
		}
		else
		{
			cin >> p;
			p--;
			long long ans = 0;
			low = 0, high = p-1;
			ans += getSumb(1);
			low = p+K, high = N-1;
			ans += getSuma(1);
			cout << ans << '\n';
		}
	}
}
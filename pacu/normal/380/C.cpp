#include <iostream>
#include <string>
using namespace std;

#define SEG (1<<20)

int a[2*SEG],b[2*SEG],c[2*SEG],l[2*SEG],r[2*SEG];
string s;

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		a[i] = b[i] = c[i] = 0;
		if((i-SEG)<s.size())
		{
			b[i] = (s[i-SEG]=='(');
			c[i] = 1-b[i];
		}
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		a[i] = a[2*i]+a[2*i+1]+min(b[2*i],c[2*i+1]);
		b[i] = b[2*i]+b[2*i+1]-min(b[2*i],c[2*i+1]);
		c[i] = c[2*i]+c[2*i+1]-min(b[2*i],c[2*i+1]);
		l[i] = l[2*i];
		r[i] = r[2*i+1];
	}
}

void getBest(int i,int low,int high,int &x,int &y,int &z)
{
	if((l[i]>high)||(r[i]<low))
	{
		x = y = z = 0;
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		x = a[i];
		y = b[i];
		z = c[i];
		return;
	}
	int d,e,f,m,n,o;
	getBest(2*i,low,high,d,e,f);
	getBest(2*i+1,low,high,m,n,o);
	x = d+m+min(e,o);
	y = e+n-min(e,o);
	z = f+o-min(e,o);
	return;
}

int main()
{
	int Q;
	cin >> s >> Q;
	init();
	int ll,rr,x,y,z;
	for(int i=0;i<Q;i++)
	{
		cin >> ll >> rr;
		ll--,rr--;
		getBest(1,ll,rr,x,y,z);
		cout << 2*x << "\n";
	}
	return 0;
}
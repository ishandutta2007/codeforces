#include <iostream>
#include <iomanip>
using namespace std;
#define SEG (1<<18)
#define ff long double

long double A[SEG];
int d[SEG];
int p[SEG];
int N,M,C;

long double seg[2*SEG],f1[2*SEG],f2[2*SEG],tot[2*SEG],l[2*SEG],r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		seg[i] = f1[i] = f2[i] = max(A[i-SEG],0.0l);
		tot[i] = A[i-SEG];
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		seg[i] = max(max(seg[2*i],seg[2*i+1]),f2[2*i]+f1[2*i+1]);
		f1[i] = max(f1[2*i],tot[2*i]+f1[2*i+1]);
		f2[i] = max(f2[2*i+1],tot[2*i+1]+f2[2*i]);
		tot[i] = tot[2*i]+tot[2*i+1];
		l[i] = l[2*i];
		r[i] = r[2*i+1];
	}
}

int low,high;

void getBest(int i,ff &best,ff &a1,ff &a2, ff &t)
{
	if((l[i]>high)||(r[i]<low))
	{
		best = a1 = a2 = t = 0;
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		best = seg[i];
		a1 = f1[i];
		a2 = f2[i];
		t = tot[i];
		return;
	}
	ff bL,a1L,a2L,tL,bR,a1R,a2R,tR;
	getBest(2*i,bL,a1L,a2L,tL);
	getBest(2*i+1,bR,a1R,a2R,tR);
	best = max(max(bL,bR),a2L+a1R);
	a1 = max(a1L,tL+a1R);
	a2 = max(a2R,tR+a2L);
	t = tL+tR;
	return;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M >> C;
	int a,b;
	cin >> a;
	N--;
	for(int i=0;i<N;i++)
	{
		cin >> b;
		d[i] = b-a;
		a = b;
	}
	for(int i=0;i<N;i++)
		cin >> p[i];
	for(int i=0;i<N;i++)
	{
		A[i] = (((long double)d[i])/2.0)-(((long double)p[i])/100.0)*C;
	}
	long double ans = 0;
	ff bb,ll,rr,tt;
	init();
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		low = a-1;
		high = b-2;
		getBest(1,bb,ll,rr,tt);
		ans += bb;
	}
	cout << fixed << setprecision(20) << ans << "\n";
	return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.14159265358979323

#define SEG (1<<19)
double x[2*SEG],y[2*SEG];
int cura[2*SEG];
int up[2*SEG];
int l[2*SEG],r[2*SEG];

int N,Q;

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		if(i-SEG < N) x[i] = 1;
		else x[i] = 0;
		y[i] = up[i] = 0;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		x[i] = x[2*i]+x[2*i+1];
		y[i] = up[i] = 0;
		l[i] = l[2*i], r[i] = r[2*i+1];
	}
}

double cosval[360],sinval[360];

void push(int i)
{
	if(up[i])
	{
		double tmpx = cosval[up[i]]*x[i]-sinval[up[i]]*y[i];
		double tmpy = sinval[up[i]]*x[i]+cosval[up[i]]*y[i];
		x[i] = tmpx, y[i] = tmpy;
		if(i<SEG) up[2*i] = (up[2*i]+up[i])%360, up[2*i+1] = (up[2*i+1]+up[i])%360;
		up[i] = 0;
	}
}

int low,high,ang;
void update(int i)
{
	if((l[i]>high)||(r[i]<low))
	{
		push(i);
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		up[i] = (up[i]+ang)%360;
		push(i);
		return;
	}
	push(i);
	update(2*i);
	update(2*i+1);
	x[i] = x[2*i]+x[2*i+1];
	y[i] = y[2*i]+y[2*i+1];
}

int len;

void updateLen(int i)
{
	if((l[i]>high)||(r[i]<low))
	{
		push(i);
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		push(i);
		double c = (len/sqrt(x[i]*x[i]+y[i]*y[i]))+1;
		x[i] *= c, y[i] *= c;
		return;
	}
	push(i);
	updateLen(2*i);
	updateLen(2*i+1);
	x[i] = x[2*i]+x[2*i+1];
	y[i] = y[2*i]+y[2*i+1];
}

int main()
{
	ios::sync_with_stdio(0);
	int M;
	cin >> N >> M;
	init();
	for(int i=0;i<360;i++)
	{
		cosval[i] = cos(i*(PI/180.0));
		sinval[i] = sin(i*(PI/180.0));
	}
	int qx,qy,qz;
	cout << fixed << ' ' << setprecision(20);
	for(int i=0;i<M;i++)
	{
		cin >> qx >> qy >> qz;
		if(qx==1)
		{
			low = high = qy-1;
			len = qz;
			updateLen(1);
		}
		else
		{
			low = qy-1, high = N-1;
			ang = 360-qz;
			update(1);
		}
		push(1);
		cout << x[1] << ' ' << y[1] << '\n';
	}
}
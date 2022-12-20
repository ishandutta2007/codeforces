#include <iostream>
using namespace std;
#define SEG (1<<17)

int seg[2*SEG][20],up[2*SEG][20],l[2*SEG],r[2*SEG];
int A[2*SEG];

void init(int k)
{
	for(int i=SEG;i<2*SEG;i++)
	{
		l[i] = r[i] = i-SEG;
		up[i][k] = 0;
		seg[i][k] = ((A[i-SEG]&(1<<k)))>0;
	}
	for(int i=SEG-1;i>0;i--)
	{
		l[i] = l[2*i];
		r[i] = r[2*i+1];
		up[i][k] = 0;
		seg[i][k] = seg[2*i][k] + seg[2*i+1][k];
	}
//	cout << k << " " << seg[1][k] << endl;
}

void push(int i,int k)
{
	if(up[i][k])
	{
		if(i<SEG)
		{
			up[2*i][k] ^= up[i][k];
			up[2*i+1][k] ^= up[i][k];
		}
		seg[i][k] = (r[i]+1-l[i])-seg[i][k];
		up[i][k] = 0;
	}
}

void xop(int i,int k,int low,int high)
{
	push(i,k);
	if((l[i]>high)||(r[i]<low)) return;
	if((l[i]>=low)&&(r[i]<=high))
	{
		up[i][k] ^= 1;
		push(i,k);
		return;
	}
	xop(2*i,k,low,high);
	xop(2*i+1,k,low,high);
	seg[i][k] = seg[2*i][k]+seg[2*i+1][k];
}

int getSum(int i,int k,int low,int high)
{
	push(i,k);
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i][k];
	return getSum(2*i,k,low,high)+getSum(2*i+1,k,low,high);
}

int main()
{
	ios::sync_with_stdio(0);
	int N,a;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int M,t,lo,hi,x;
	long long ans;
	cin >> M;
	for(int j=0;j<20;j++)
		init(j);
	for(int i=0;i<M;i++)
	{
		cin >> t;
		if(t==1)
		{
			cin >> lo >> hi;
			lo--,hi--;
			ans = 0;
			for(int j=0;j<20;j++)
				ans += (((long long)getSum(1,j,lo,hi))<<j);
			cout << ans << "\n";
		}
		else
		{
			cin >> lo >> hi >> x;
			lo--,hi--;
			for(int j=0;j<20;j++)
				if(x&(1<<j))
					xop(1,j,lo,hi);
		}
	}
}
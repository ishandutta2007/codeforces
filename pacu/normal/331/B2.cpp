#include <iostream>
using namespace std;
#define SEG (1<<19)

int seg[2*SEG],l[2*SEG],r[2*SEG];
int A[SEG];
int B[SEG];
int N;

void init()
{
	for(int i=N;i<SEG;i++)
		A[i] = 1000000000;
	for(int i=SEG;i<2*SEG;i++)
	{
		seg[i] = 0;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		seg[i] = seg[2*i]+seg[2*i+1]+(A[r[2*i]]>A[l[2*i+1]]);
		l[i] = l[2*i], r[i] = r[2*i+1];
	}
}

void update(int i,int j)
{
	i += SEG, j += SEG;
	for(i/=2;i>0;i/=2)
		seg[i] = seg[2*i]+seg[2*i+1]+(A[r[2*i]]>A[l[2*i+1]]);
	for(j/=2;j>0;j/=2)
		seg[j] = seg[2*j]+seg[2*j+1]+(A[r[2*j]]>A[l[2*j+1]]);
}

int low,high;
int getShaves(int i)
{
	if((l[i]>high)||(r[i]<low)) return -1;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	int a = getShaves(2*i);
	int b = getShaves(2*i+1);
	if(a==-1) return b;
	if(b==-1) return a;
	return a+b+(A[r[2*i]]>A[l[2*i+1]]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> B[i];
		B[i]--;
		A[B[i]] = i;
	}
	init();
	int Q,tp,x,y;
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		cin >> tp >> x >> y;
		x--,y--;
		if(tp==1)
		{
			low = x, high = y;
			cout << getShaves(1)+1 << "\n";
		}
		else
		{
			swap(B[x],B[y]);
			swap(A[B[x]],A[B[y]]);
			update(B[x],B[y]);
		}
	}
	return 0;
}
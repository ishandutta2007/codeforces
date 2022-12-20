#include <iostream>
#include <algorithm>
using namespace std;
#define SEGN (1<<17)
#define SEGK (1<<14)
#define INF 2000000000

int N,K;
int B[SEGN];

int segB[2*SEGN];
int bl[2*SEGN];
int br[2*SEGN];

void initSegB()
{
	for(int i=SEGN;i<2*SEGN;i++)
	{
		bl[i] = br[i] = i-SEGN;
		if(i-SEGN < N) segB[i] = B[i-SEGN];
		else segB[i] = INF;
	}
	for(int i=SEGN-1;i>0;i--)
	{
		bl[i] = bl[2*i], br[i] = br[2*i+1];
		segB[i] = min(segB[2*i], segB[2*i+1]);
	}
}

int ch[20000000][2];
int val[20000000];
int up[20000000];
int C;

void pushInner(int i,int bi)
{
	if(up[i]>0)
	{
		val[i] = up[i];
		if(bi<SEGN)
		{
			if(ch[i][0] == 0)
			{
				ch[i][0] = C++;
				ch[i][1] = C++;
			}
			up[ch[i][0]] = up[ch[i][1]] = up[i];
		}
		up[i] = 0;
	}
}

int lowInner,highInner;

void updateInner(int i,int bi,int x)
{
	if((bl[bi]>highInner)||(br[bi]<lowInner))
	{
		pushInner(i,bi);
		return;
	}
	if((bl[bi]>=lowInner)&&(br[bi]<=highInner))
	{
		up[i] = x;
		pushInner(i,bi);
		return;
	}
	pushInner(i,bi);
	if(ch[i][0]==0)
	{
		ch[i][0] = C;
		val[C] = segB[2*bi];
		C++;
		ch[i][1] = C;
		val[C] = segB[2*bi+1];
		C++;
	}
	updateInner(ch[i][0],2*bi,x);
	updateInner(ch[i][1],2*bi+1,x);
	val[i] = min(val[ch[i][0]],val[ch[i][1]]);
}

int getMinInner(int i,int bi)
{
	if((bl[bi]>highInner)||(br[bi]<lowInner)) return INF;
	pushInner(i,bi);
	if((bl[bi]>=lowInner)&&(br[bi]<=highInner)) return val[i];
	if(ch[i][0]==0)
	{
		ch[i][0] = C;
		val[C] = segB[2*bi];
		C++;
		ch[i][1] = C;
		val[C] = segB[2*bi+1];
		C++;
	}
	return min(getMinInner(ch[i][0],2*bi),getMinInner(ch[i][1],2*bi+1));
}

int l[2*SEGK];
int r[2*SEGK];

void init()
{
	for(int i=SEGK;i<2*SEGK;i++)
	{
		l[i] = (i-SEGK)*SEGN;
		r[i] = l[i] + SEGN - 1;
		val[i] = segB[1];
	}
	for(int i=SEGK-1;i>0;i--)
	{
		l[i] = l[2*i], r[i] = r[2*i+1];
		val[i] = segB[1];
	}
}

void push(int i)
{
	if(up[i]>0)
	{
		val[i] = up[i];
		up[2*i] = up[2*i+1] = up[i];
		up[i] = 0;
	}
}

int low,high;

void update(int i,int x)
{
	if(i >= SEGK)
	{
		pushInner(i,1);
		lowInner = max(low,l[i]);
		highInner = min(high,r[i]);
		if(highInner<lowInner) return;
		lowInner %= SEGN, highInner %= SEGN;
		updateInner(i,1,x);
		return;
	}
	if((l[i]>high)||(r[i]<low))
	{
		push(i);
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		up[i] = x;
		push(i);
		return;
	}
	push(i);
	update(2*i,x);
	update(2*i+1,x);
	val[i] = min(val[2*i],val[2*i+1]);
}

int getMin(int i)
{
	//cout << i << ": " << l[i] << ' ' << r[i] << '\n';
	if(i >= SEGK)
	{
		pushInner(i,1);
		lowInner = max(low,l[i]);
		highInner = min(high,r[i]);
		if(highInner<lowInner) return INF;
		lowInner %= SEGN, highInner %= SEGN;
		int v = getMinInner(i,1);
//		cout << l[i] << ' ' << r[i] << ": " << v << '\n';
		return v;
	}
	push(i);
	if((l[i]>high)||(r[i]<low)) return INF;
	if((l[i]>=low)&&(r[i]<=high)) return val[i];
	return min(getMin(2*i),getMin(2*i+1));
}

int adjustIndex(int i)
{
	int block = i/N;
	int loc = i%N;
	return block*SEGN + loc;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> K;
	for(int i=0;i<N;i++)
	{
		cin >> B[i];
		//B[i] = i+1;
	}
	initSegB();
	init();
	C = 2*SEGK;
	int Q;
	cin >> Q;
	int tp,ql,qr,qx;
	for(int i=0;i<Q;i++)
	{
		cin >> tp >> ql >> qr;
		ql--,qr--;
		low = adjustIndex(ql);
		high = adjustIndex(qr);
		//cout << low << ' ' << high << '\n';
		if(tp==1)
		{
			cin >> qx;
			update(1,qx);
//			for(int j=ql;j<=qr;j++)
//				A[j] = qx;
		}
		else
		{
			cout << getMin(1) << '\n';
//			int v = INF;
//			for(int j=ql;j<=qr;j++)
//				v = min(v,A[j]);
//			int w = getMin(1);
//			if(w != v) cout << "BAD\n";
		}
	}
}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int X1,Y1,X2,Y2;
int W1,Z1,W2,Z2;
/*
int cnt = 0;
int q(int x1,int y1,int x2,int y2)
{
	cnt++;
	int ans = 0;
	if(x1<=X1 && y1 <= Y1 && x2 >= X2 && y2 >= Y2) ans++;
	if(x1<=W1 && y1 <= Z1 && x2 >= W2 && y2 >= Z2) ans++;
	return ans;
}
*/
int N;

int q(int x1,int y1,int x2,int y2)
{
	if(x2<=x1 || y2<=y1) return 0;
	cout << "? " << x1+1 << ' ' << y1+1 << ' ' << x2 << ' ' << y2 << '\n';
	fflush(stdout);
	int a;
	cin >> a;
	return a;
}

int x1,y1,x2,y2;

int binSearchRight(int low,int high,int thresh)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(q(x1,y1,low,y2)>=thresh) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(q(x1,y1,mid,y2)>=thresh) return binSearchRight(low,mid,thresh);
	else return binSearchRight(mid+1,high,thresh);
}

int binSearchLeft(int low,int high,int thresh)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(q(high,y1,x2,y2)>=thresh) return high;
		return low;
	}
	int mid = (low+high)/2;
	if(q(mid,y1,x2,y2)>=thresh) return binSearchLeft(mid,high,thresh);
	else return binSearchLeft(low,mid-1,thresh);
}

int binSearchTop(int low,int high,int thresh)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(q(x1,y1,x2,low)>=thresh) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(q(x1,y1,x2,mid)>=thresh) return binSearchTop(low,mid,thresh);
	else return binSearchTop(mid+1,high,thresh);
}

int binSearchBottom(int low,int high,int thresh)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(q(x1,high,x2,y2)>=thresh) return high;
		return low;
	}
	int mid = (low+high)/2;
	if(q(x1,mid,x2,y2)>=thresh) return binSearchBottom(mid,high,thresh);
	else return binSearchBottom(low,mid-1,thresh);
}

int x[4];
int y[4];

int ax1,ax2,ay1,ay2;
int bx1,bx2,by1,by2;

int main()
{
	cin >> N;
//	cin >> X1 >> Y1 >> X2 >> Y2 >> W1 >> Z1 >> W2 >> Z2;
	x1 = 0, y1 = 0, x2 = N, y2 = N;
	x[3] = binSearchRight(0,N,2);
	x[0] = binSearchLeft(0,N,2);
	y[3] = binSearchTop(0,N,2);
	y[0] = binSearchBottom(0,N,2);
	x1 = x[0], x2 = x[3], y1 = y[0], y2 = y[3];
	x[2] = binSearchRight(0,N,1);
	x[1] = binSearchLeft(0,N,1);
	y[2] = binSearchTop(0,N,1);
	y[1] = binSearchBottom(0,N,1);
	sort(x,x+4);
	sort(y,y+4);
	if(q(x[1],0,x[2],N)==1)
	{
		ax1 = x[0], ax2 = x[3], bx1 = x[1], bx2 = x[2];
	}
	else if(q(x[0],0,x[1],N)==1)
	{
		ax1 = x[0], ax2 = x[1], bx1 = x[2], bx2 = x[3];
	}
	else
	{
		ax1 = x[0], ax2 = x[2], bx1 = x[1], bx2 = x[3];
	}
	if(q(0,y[1],N,y[2])==1)
	{
		ay1 = y[0], ay2 = y[3], by1 = y[1], by2 = y[2];
	}
	else if(q(0,y[0],N,y[1])==1)
	{
		ay1 = y[0], ay2 = y[1], by1 = y[2], by2 = y[3];
	}
	else
	{
		ay1 = y[0], ay2 = y[2], by1 = y[1], by2 = y[3];
	}
	
	if(q(ax1,ay1,ax2,ay2)!=1 || q(bx1,by1,bx2,by2)!=1)
	{
		swap(ay1,by1);
		swap(ay2,by2);
	}

	cout << "! " << ax1+1 << ' ' << ay1+1 << ' ' << ax2 << ' ' << ay2 << ' ' << bx1+1 << ' ' << by1+1 << ' ' << bx2 << ' ' << by2 << '\n';
	fflush(stdout);
	//cout << cnt << '\n';
}
/*
int main()
{
	N = 10;
	for(X1=0;X1<=10;X1++)
		for(X2=X1+1;X2<=10;X2++)
			for(Y1=0;Y1<=10;Y1++)
				for(Y2=Y1+1;Y2<=10;Y2++)
					for(W1=0;W1<=10;W1++)
						for(W2=W1+1;W2<=10;W2++)
							for(Z1=0;Z1<=10;Z1++)
								for(Z2=Z1+1;Z2<=10;Z2++)
								{
									if(max(X1,W1)>=min(X2,W2) || max(Y1,Z1)>=min(Y2,Z2))
										test();
								}
}*/
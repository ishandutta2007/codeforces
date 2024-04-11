#include <bits/stdc++.h>

using namespace std;

const int N = 512;

struct LR {
	int l , r;
	LR(int l = 0 , int r = 0) : l(l) , r(r) {}
};

int n , t1[N];
char m[N][N];
int row[N] , col[N] , mark[N];
int q[N] , cq;

void gg()
{
	printf("NO\n");
	exit(0);
}

void reverseC(int c1 , int c2)
{
	while(c1 < c2)
		swap(col[c1++] , col[--c2]);
}

LR getLR(int row , int c1 , int c2)
{
	int lf = n , rf = 0;
	for(int c = c1; c < c2; c++)
		if(m[row][col[c]] == '1')
		{
			lf = min(mark[col[c]] , lf);
			rf = max(mark[col[c]] , rf);
		}
	return LR(lf , rf);
}

int markRight(int c , int cright)
{
	int cz = c;
	while(cz < cright && mark[col[cz]] == mark[col[c]])
		++cz;
	return cz;
}

int sortRow(int row , int c1 , int c2)
{
	cq = 0;
	for(int i = c1; i < c2; i++)
		if(m[row][col[i]] == '1')
			q[cq++] = col[i];
	int ret = cq;
	for(int i = c1; i < c2; i++)
		if(m[row][col[i]] == '0')
			q[cq++] = col[i];
	for(int i = c1; i < c2; i++)
		col[i] = q[i - c1];
	return c1 + ret;
}

void reMarks(int row , int c1 , int c2)
{
	int cur = c1;
	q[col[c1]] = cur;
	for(int c = c1 + 1; c < c2; c++)
	{
		if(mark[col[c]] == mark[col[c - 1]] && m[row][col[c]] == m[row][col[c - 1]])
			q[col[c]] = cur;
		else
			q[col[c]] = cur = c;
	}
	for(int c = c1; c < c2; c++)
		mark[col[c]] = q[col[c]];
}

void solve(int r1 , int r2 , int c1 , int c2)
{
	int sel = -1 , selt = -1;
	for(int r = r1; r < r2; r++)
		if(t1[row[r]] > selt)
			selt = t1[row[sel = r]];
	swap(row[r1] , row[sel]);
	int mid = sortRow(row[r1] , c1 , c2);
	reMarks(row[r1] , c1 , c2);
	for(int cr = r1 + 1; cr < r2; cr++)
	{
		int selRow = -1 , minL = n + 1 , maxR = -1;
		for(int r = cr; r < r2; r++)
		{
			LR lr = getLR(row[r] , c1 , c2);
			if(lr.l < minL || lr.l == minL && lr.r > maxR)
				selRow = r , minL = lr.l , maxR = lr.r;
		}
		if(minL == maxR)
		{
			int pp = cr;
			for(int r = cr; r < r2; r++)
			{
				LR lr = getLR(row[r] , c1 , c2);
				if(lr.l == minL && lr.r == maxR)
					swap(row[r] , row[pp++]);
			}
			solve(cr , pp , minL , markRight(minL , c2));
			cr = pp - 1;
		}
		else
		{
			swap(row[cr] , row[selRow]);
			int Row = row[cr];
			int cx = minL;
			while(cx < c2)
			{
				int cy = markRight(cx , c2);
				sortRow(Row , cx , cy);
				cx = cy;
			}
			bool already = false;
			cx = c1;
			while(cx < mid)
			{
				int cy = markRight(cx , c2);
				if(cy >= mid)
					break;
				if(m[Row][col[cx]] == '1' && m[Row][col[cy - 1]] == '0' && m[Row][col[cy]] == '1')
				{
					if(already)
						gg();
					reverseC(cx , cy);
					already = 1;
				}
				cx = cy;
			}
			reMarks(Row , c1 , c2);
			if(m[Row][col[mid]] == '1')
			{
				int nmid = markRight(mid , c2);
				if(m[Row][col[mid - 1]] == '0' && already == 0 && (m[Row][col[cx - 1]] == '0'))
				{
//					cout << "Run" << endl;
//					for(int i = 0; i < n; i++)
//						cout << m[Row][col[i]];
//					cout << endl;
//					for(int i = 0; i < n; i++)
//						cout << mark[col[i]] << " ";
//					cout << c1 << " " << c2 << endl;
//					cout << cx << " " << mid << endl;
//					for(int i = cx; i < mid; i++)
//						cout << m[Row][col[i]];
//					cout << endl;
					reverseC(cx , mid);
				}
				if(m[Row][col[mid - 1]] == '0')
				{
					cq = 0;
					for(int i = mid; i < nmid; i++)
						q[cq++] = col[i];
					for(int i = c1; i < mid; i++)
						q[cq++] = col[i];
					for(int i = c1; i < nmid; i++)
						col[i] = q[i - c1];
				}
				mid = nmid;
				reMarks(Row , c1 , c2);
			}
			int cnt = (m[Row][col[c1]] - '0');
			for(int c = c1 + 1; c < c2; c++)
				if(m[Row][col[c - 1]] == '0' && m[Row][col[c]] == '1')
					cnt++;
			if(cnt > 1)
				gg();
		}
	}
}

int main()
{
	scanf("%d" , &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s" , m[i]);
		for(int j = 0; j < n; j++)
			t1[i] += m[i][j] - '0';
		row[i] = col[i] = i;
	}
	solve(0 , n , 0 , n);
	printf("YES\n");
	for(int i = 0; i < n; i++ , printf("\n"))
		for(int j = 0; j < n; j++)
			printf("%c" , m[i][col[j]]);
	return 0;
}
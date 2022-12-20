#include <iostream>
#include <vector>
using namespace std;
int n,m;
int aUsed[301][301];
void next(int &ncol,int &nrow,int col,int row)
{
	aUsed[col][row] = 1;
	if((col<m)&&(!aUsed[col+1][row]))
	{
		ncol = col + 1;
		nrow = row;
		return;
	}
	if((row<n)&&(!aUsed[col][row+1]))
	{
		ncol = col;
		nrow = row + 1;
		return;
	}
	if((col>1)&&(!aUsed[col-1][row]))
	{
		ncol = col -1;
		nrow = row;
		return;
	}
	ncol = col;
	nrow = row - 1;
}

int main()
{
	int k;
	int cBlocks;
	int i;
	int row,col,nrow,ncol;
	int rem;
	cin >> n >> m >> k;
	row = col = 1;
	cBlocks = 0;
	rem = n*m;
	while(cBlocks<(k-1))
	{
		next(ncol,nrow,col,row);
		cout << 2 << " " << row << " " << col << " " << nrow << " " << ncol << endl;
		next(col,row,ncol,nrow);
		rem -= 2;
		cBlocks++;
	}
	cout << rem;
	while(rem)
	{
		next(ncol,nrow,col,row);
		cout << " " << row << " " << col;
		rem--;
		row = nrow;
		col = ncol;
	}
	cout << endl;
}
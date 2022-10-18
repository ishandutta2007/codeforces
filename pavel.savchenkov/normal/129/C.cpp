#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> s;
queue <int> g;
queue <int> rank;

void add(int i,int j,int k)
{
	if (i<1||i>8||j<1||j>8) return;
	for (int x=0;x<(int)s.size();x++)
		if (s[x]+8*k==8*(i-1)+j) return;
	g.push(8*(i-1)+j); rank.push(k+1);
}

int main() {
	for (int i=1;i<=8;i++)
	{
		for (int j=1;j<=8;j++)
			{char c; scanf("%c",&c); if (c=='S') s.push_back(8*(i-1)+j);}
		scanf("\n");
	}

	g.push(57); rank.push(0);
	while (!g.empty())
	{
		int q=g.front(); g.pop();
		int k=rank.front(); rank.pop();
		if (k==8) {printf("WIN");return 0;}
		int i=(q+1)/8+1,j=q%8; if (j==0) j=8; bool can=true;
		for (int x=0;x<(int)s.size();x++)
			if (s[x]+8*k==q) can=false;
		if (!can) continue;
		if (q==8) {puts("WIN");return 0;}
		add(i,j-1,k); add(i,j+1,k); add(i-1,j+1,k); add(i-1,j-1,k);
		add(i-1,j,k); add(i+1,j-1,k); add(i+1,j+1,k); add(i+1,j,k);
		add(i,j,k);
	}
	puts("LOSE");
	return 0;
}
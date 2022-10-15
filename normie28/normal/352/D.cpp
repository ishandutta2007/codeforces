#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define endl "\n"
#define sect 3200
struct el { string word; long long x, y, dir; };
long long n, m, k, cnt, i, j, x, a = 1e10, b = 0, c=0,  reg[5000];
char mp[1000][1000];
string name[8] = { "N","NE","E","SE","S","SW","W","NW" };
	int sum[2000001];
vector<long long> ord;
int dist(int a,int b,int c,int d) {return int(abs((a)-(c))+abs((b)-(d)));}
double prob[10000000];
int valid (int x, int y)
{
	return ((x>=0)and(x<n)and(y>=0)and(y<m)); 
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>reg[i];
	}
	for (i=1;i<=n;i++)
	for (j=i+1;j<=n;j++) if (reg[i]>reg[j]) c++;
	prob[0]=0;
	prob[1]=1;
	for (i=2;i<=c;i++) prob[i]=(prob[i-2])+4;
	cout<<fixed<<setprecision(10)<<prob[c];
	fclose(stdin);
	fclose(stdout);
}
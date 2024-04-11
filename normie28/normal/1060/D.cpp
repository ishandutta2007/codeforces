#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define endl "\n"
#define sect 3200
struct el { string word; long long x, y, dir; };
long long n, m, k, cnt, i, j, x, a = 1e10, b = 0, c=0,  reg[1000][1000];
char mp[1000][1000];
string name[8] = { "N","NE","E","SE","S","SW","W","NW" };
	int sum[2000001];
vector<long long> aa,bb;
int dist(int a,int b,int c,int d) {return int(abs((a)-(c))+abs((b)-(d)));}
int valid (int x, int y)
{
	return ((x>=0)and(x<n)and(y>=0)and(y<m)); 
}
int main()
{
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>a>>b;
		aa.push_back(a);
		bb.push_back(b);
	}
	sort(aa.begin(),aa.end());
	sort(bb.begin(),bb.end());
	for (i=0;i<n;i++) c+=max(aa[i],bb[i]);
	cout<<c+n;
	fclose(stdin);
	fclose(stdout);
}
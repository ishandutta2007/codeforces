#include <iostream>
#include <algorithm>
using namespace std;

int N,G,K,S;

long long gcost[200000];
int a[200000],b[200000];
int t[200000],c[200000];

bool pos(int d)
{
	int la = 1000000001;
	int lb = 1000000001;
	for(int i=0;i<=d;i++)
	{
		la = min(la,a[i]);
		lb = min(lb,b[i]);
	}
	for(int i=0;i<G;i++)
	{
		if(t[i]==1) gcost[i] = ((long long)c[i])*((long long)la);
		else gcost[i] = ((long long)c[i])*((long long)lb);
	}
	sort(gcost,gcost+G);
	long long mleft = S;
	for(int i=0;i<K;i++)
		mleft -= gcost[i];
	return mleft >= 0;
}

int binSearch(int low,int high)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(pos(low)) return low;
		return high;
	}
	int mid = (low+high)/2;
	if(pos(mid)) return binSearch(low,mid);
	else return binSearch(mid+1,high);
}

bool cmp(int x,int y)
{
	return gcost[x]<gcost[y];
}
int cid[200000];

int main()
{
	cin >> N >> G >> K >> S;
	for(int i=0;i<N;i++)
		cin >> a[i];
	for(int i=0;i<N;i++)
		cin >> b[i];
	for(int i=0;i<G;i++)
		cin >> t[i] >> c[i];
	if(!pos(N-1))
	{
		cout << -1 << '\n';
		return 0;
	}
	int ans = binSearch(0,N-1);
	int la = 0;
	int lb = 0;
	for(int i=0;i<=ans;i++)
	{
		if(a[i] < a[la]) la = i;
		if(b[i] < b[lb]) lb = i;
	}
	for(int i=0;i<G;i++)
	{
		if(t[i]==1) gcost[i] = ((long long)c[i])*((long long)a[la]);
		else gcost[i] = ((long long)c[i])*((long long)b[lb]);
		cid[i] = i;
	}
	sort(cid,cid+G,cmp);
	cout << ans+1 << '\n';
	for(int i=0;i<K;i++)
	{
		if(t[cid[i]] == 1) cout << cid[i]+1 << ' ' << la+1 << '\n';
		else cout << cid[i]+1 << ' ' << lb+1 << '\n';
	}
}
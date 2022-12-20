#include <iostream>
#include <set>
using namespace std;

int h[100002];
int N;

struct cmp
{
	bool operator()(int a,int b)
	{
		if(h[a]==h[b])
			return a<b;
		return h[a]<h[b];
	}
};

set<int,cmp> S;

int main()
{
	cin >> N;
	h[0] = 0;
	h[N+1] = 0;
	for(int i=1;i<=N;i++)
		cin >> h[i];
	N += 2;
	for(int i=0;i<N;i++)
		S.insert(i);
	int ans = 0;
	while(S.size() > 0)
	{
		int cur = *S.begin();
		ans = h[cur];
		if(cur > 0 && h[cur]+1 < h[cur-1])
		{
			S.erase(S.find(cur-1));
			h[cur-1] = h[cur]+1;
			S.insert(cur-1);
		}
		if(cur < (N-1) && h[cur]+1 < h[cur+1])
		{
			S.erase(S.find(cur+1));
			h[cur+1] = h[cur]+1;
			S.insert(cur+1);
		}
		S.erase(S.find(cur));
	}
	cout << ans << '\n';
}
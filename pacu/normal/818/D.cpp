#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N,A;
int cnt[1000001];
bool bad[1000001];

struct cmp
{
	bool operator()(int a,int b) const
	{
		if(cnt[a]==cnt[b]) return a<b;
		return cnt[a]<cnt[b];
	}
};

set<int,cmp> S;

int main()
{
	cin >> N >> A;
	int c;
	for(int i=1;i<=1000000;i++)
		S.insert(i);
	for(int i=0;i<N;i++)
	{
		cin >> c;
		if(cnt[c] < cnt[A]) bad[c] = 1;
		if(!bad[c])
		{
			S.erase(c);
			cnt[c]++;
			S.insert(c);
		}
		while(cnt[*S.begin()] < cnt[A])
			S.erase(S.begin());
	}
	if(S.size()==1) cout << -1 << '\n';
	else if(*S.begin() != A) cout << *S.begin() << '\n';
	else
	{
		S.erase(S.begin());
		cout << *S.begin() << '\n';
	}
}
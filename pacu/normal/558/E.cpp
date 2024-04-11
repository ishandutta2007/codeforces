#include <iostream>
#include <set>
#include <string>
using namespace std;

char s[100005];
int N;

struct ch
{
	int pos;
	char c;
	ch(int p,char cc)
	{
		pos = p;
		c = cc;
	}
};

struct cmp
{
	bool operator()(ch a,ch b)
	{
		return a.pos<b.pos;
	}
};

multiset<ch,cmp> S;

int main()
{
	int Q;
	cin >> N >> Q;
	s[0] = '$';
	cin >> s+1;
	s[N+1] = '$';
	for(int i=0;i<=N;i++)
		if(i==0 || s[i]!=s[i-1])
			S.insert(ch(i,s[i]));
	S.insert(ch(N+1,'$'));
	int l,r,k;
	multiset<ch,cmp>::iterator it,it2;
	int cnt[26];
	for(int i=0;i<Q;i++)
	{
		cin >> l >> r >> k;
		it2 = it = S.upper_bound(ch(l,'a'));
		it--;
		for(int j=0;j<26;j++)
			cnt[j] = 0;
		cnt[(*it).c-'a'] = (*it2).pos-l;
		for(it2++,it++;(*it).pos<=r;it2++,it++)
		{
			cnt[(*it).c-'a'] += min(r+1,(*it2).pos)-(*it).pos;
		}
		it = S.upper_bound(ch(r+1,'a'));
		it--;
		if((*it).pos <= r)
			S.insert(ch(r+1,(*it).c));
		else
			it--;
		while((*it).pos >= l)
		{
			it2 = it;
			it--;
			S.erase(it2);
		}
		int cur = l;
		if(k==1)
		{
			for(int j=0;j<26;j++)
			{
				if(cnt[j])
				{
					S.insert(ch(cur,(char)(j+'a')));
					cur += cnt[j];
				}
			}
		}
		else
		{
			for(int j=25;j>=0;j--)
			{
				if(cnt[j])
				{
					S.insert(ch(cur,(char)(j+'a')));
					cur += cnt[j];
				}
			}
		}
	}
	string t;
	it = S.begin();
	for(it++;(*it).c != '$';it++)
	{
		it2 = it;
		it2++;
		for(int i=0;i<((*it2).pos-(*it).pos);i++)
			t += (*it).c;
	}
	cout << t << '\n';
}
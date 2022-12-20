#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int T[300000];
void init(int n)
{
	for(int i=0;i<=n;i++)
		T[i] = 0;
}
int getSum(int i)
{
	int c=0;
	for(i++;i>0;i-=(i&-i))
		c += T[i];
	return c;
}
void set(int i,int d)
{
	for(++i;i<300000;i+=(i&-i))
		T[i] = T[i]+d;
}

int pos[200000];
int vel[200000];
int cval[200000];
int cid[200000];

map<int,int> m;

bool cmp(int a,int b)
{
	return cval[a]<cval[b];
}

int main()
{
	int N;
	int a,b;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		if(m.find(a)==m.end())
			m[a] = a;
		if(m.find(b)==m.end())
			m[b] = b;
		swap(m[a],m[b]);
	}
	int k = 0;
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	{
		pos[k] = it->first;
		cval[k] = vel[k] = it->second;
		cid[k] = k;
		k++;
	}
	long long ans = 0;

	sort(cid,cid+k,cmp);
	for(int i=0;i<k;i++)
		cval[cid[i]] = i+1;
	init(200005);
	for(int i=k-1;i>=0;i--)
	{
		ans += getSum(cval[i]);
		set(cval[i],1);
	}

	for(int i=0;i<k;i++)
	{
		if(vel[i]<pos[i])
		{
			//left
			int b = lower_bound(pos,pos+k,vel[i])-pos;
			ans += (pos[i]-vel[i])-(i-b);
		}
	}
	for(int i=0;i<k;i++)
	{
		vel[i] = -vel[i];
		pos[i] = -pos[i];
	}
	reverse(vel,vel+k);
	reverse(pos,pos+k);
	for(int i=0;i<k;i++)
	{
		if(vel[i]<pos[i])
		{
			//right
			int b = lower_bound(pos,pos+k,vel[i])-pos;
			ans += (pos[i]-vel[i])-(i-b);
		}
	}
	cout << ans << endl;
	return 0;
}
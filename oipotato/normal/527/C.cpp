#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
int W,H,N,x;
char ch,ord;
void getint(int &x)
{
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';x=x*10+ch-'0',ch=getchar());
}
struct glass
{
	set<int> seg;
	int maxans,num[200010];
	void init(int x){seg.insert(0);seg.insert(x);maxans=x;num[x]++;}
	void insert(int x)
	{
		set<int>::iterator it,it1;
		it=seg.find(x);
		if(it!=seg.end())return;
		else
		{
			seg.insert(x);
			it=it1=seg.find(x);it--;it1++;
			int L=*it,R=*it1;
			num[R-L]--;num[x-L]++;num[R-x]++;
			for(;!num[maxans];maxans--);
		}
	}
}SP,CZ;
int main()
{
	getint(W);getint(H);getint(N);
	SP.init(H);CZ.init(W);
	for(int i=1;i<=N;i++)
	{
		ord=getchar();getint(x);
		if(ord=='H')SP.insert(x);else CZ.insert(x);
		cout<<(long long)SP.maxans*CZ.maxans<<endl;
	}
	return 0;
}
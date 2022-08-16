# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <cctype>
# include <set>

using namespace  std;

struct two
{
	int a,ind;
}inp[100000];

bool operator<(const two& t1,const two& t2)
{
	return t1.a<t2.a;
}

int main()
{
	int N,H;
	cin>>N>>H;

	for(int i=0;i<N;i++)
	{
		cin>>inp[i].a;
		inp[i].ind=i;
	}

	sort(inp,inp+N);

	int ret=inp[N-1].a+inp[N-2].a-inp[0].a-inp[1].a,ret2;
	int type=1;
	if(N>2)
	{
		ret2=max(inp[N-1].a+inp[N-2].a,inp[N-1].a+inp[0].a+H)-min(inp[1].a+inp[2].a,inp[1].a+inp[0].a+H);
		if(ret2<ret)type=2;
	}

	if(type==1)
	{
		cout<<ret<<endl;
		for(int i=0;i<N;i++)
			cout<<1<<"\t";
		cout<<endl;
	}
	else
	{
		cout<<ret2<<endl;
		for(int i=0;i<N;i++)
			cout<<((i==inp[0].ind)?2:1)<<"\t";
		cout<<endl;
	}
	return 0;
}
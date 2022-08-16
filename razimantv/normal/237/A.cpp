# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <queue>
# include <cstring>
# include <cctype>

using namespace std;

int h[1000000],m[1000000];

int main()
{
	int N;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		cin>>h[i]>>m[i];
	}

	int best=1;
	for(int i=0;i<N;i++)
	{
		if((i!=N-1)&&(h[i+1]==h[i]&&m[i+1]==m[i]))continue;
		int lim=i-1;
		while(lim>=0&&h[lim]==h[i]&&m[lim]==m[i])lim--;
		best=max(best,i-lim);
	}
	cout<<best<<endl;

	return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 5e5+10;

std::vector<int> a[MN];
int N, M, t[MN], o[MN];
bool good=1;
int v[MN];
int main(){
	scanf("%d%d", &N, &M);
	for(int i=0,x,y;i<M;++i)
		scanf("%d%d", &x, &y), --x, --y, a[x].push_back(y), a[y].push_back(x);
	for(int i=0;i<N;++i)
		scanf("%d", t+i), o[i]=i, v[i]=1;
	std::sort(o, o+N, [](int x,int y){return t[x]<t[y];});
	for(int i=0;i<N;++i)
	{
		int n = o[i];
		if(v[n] != t[n])
		{
			good = 0;
			break;
		}
		for(int x:a[n])
			if(v[x] == t[n])
				++v[x];
	}
	if(good)
		for(int i=0;i<N;++i)
			printf("%d%c", 1+o[i], " \n"[i+1==N]);
	else
		printf("-1\n");
	return 0;
}
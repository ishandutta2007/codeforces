#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
int main()
{
	int k,n,w;
	scanf("%d%d%d",&k,&n,&w);
	w=(w+1)*w/2*k;
	printf("%d\n",max(0,w-n));
    return 0;
}
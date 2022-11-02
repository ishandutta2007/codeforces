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
	int a,b;
	scanf("%d%d",&a,&b);
	int i=0;
	for(;a<=b;i++,a*=3,b*=2);
	printf("%d\n",i);
    return 0;
}
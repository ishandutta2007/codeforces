#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
bool is_lucky(int k)
{
	if (k < 0)k = -k;
	while (k > 0){
		if (k % 10 == 8)return 1;
		else k = k / 10;
	}
	return 0;
}
int main()
{
	long long a, i;
	scanf("%I64d", &a);
	for (i = 1; i <= 20; i++){
		if (is_lucky(a + i))break;
	}
	printf("%I64d\n", i);
}
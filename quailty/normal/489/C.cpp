#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#define INF 1000000007;
using namespace std;
int bit[100];
int main()
{
	int m, s, i, temp, loc;
	scanf("%d%d", &m, &s);
	if (s == 0 && m == 1)printf("0 0\n");
	else if (s == 0 || s > 9 * m)printf("-1 -1\n");
	else{
		bit[0] = 1;
		for (i = 1; i <= m - 1; i++)bit[i] = 0;
		loc = m - 1;
		temp = s - 1;
		while (temp > 0){
			while (temp > 0 && bit[loc] < 9){
				bit[loc]++;
				temp--;
			}
			loc--;
		}
		for (i = 0; i <= m - 1; i++)printf("%d", bit[i]);
		printf(" ");
		bit[0] = 1;
		for (i = 1; i <= m - 1; i++)bit[i] = 0;
		temp = s - 1;
		loc = 0;
		while (temp > 0){
			while (temp > 0 && bit[loc] < 9){
				bit[loc]++;
				temp--;
			}
			loc++;
		}
		for (i = 0; i <= m - 1; i++)printf("%d", bit[i]);
		printf("\n");
	}
	return 0;
}
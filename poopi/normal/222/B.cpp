                                        /* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define PLL pair<int64, int64>

int n, m, k;
int r[1010], c[1010];
int mat[1010][1010];

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		r[i] = i;
	for(int i = 0; i < m; i++)
		c[i] = i;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &mat[i][j]);
	char ch[10];
	int a, b;
	for(int i = 0; i < k; i++){
		scanf("%s%d%d", ch, &a, &b);
		if(ch[0] == 'r')
			swap(r[a - 1], r[b - 1]);
		if(ch[0] == 'c')
			swap(c[a - 1], c[b - 1]);
		if(ch[0] == 'g')
			printf("%d\n", mat[r[a - 1]][c[b - 1]]);
	}
    return 0;
}
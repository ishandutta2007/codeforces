										/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

#define P pair<int, int>
#define int64 long long

int m, n, sz, cnt;
int a[1000], b[1000];
int64 sum[1000][5];
int str[1000];
int q[100010][2];
P num[100010];
bool mark[100010];

int bs(int x){
	int l = 0, r = n - 1;
	while(l < r){
		int mid = (l + r) / 2;
		if(num[mid].first >= x)
			r = mid;
		else l = mid + 1;
	}
	return l;
}

void inc(int idx){
	for(int i = idx; i < cnt; i++){
		str[i]++;
		if(str[i] == 5)
			str[i] = 0;
		int64 t = sum[i][4];
		for(int j = 4; j > 0; j--)
			sum[i][j] = sum[i][j - 1];
		sum[i][0] = t;
	}
}

void dec(int idx){
	for(int i = idx; i < cnt; i++){
		str[i]--;
		if(str[i] == -1)
			str[i] = 4;
		int64 t = sum[i][0];
		for(int j = 0; j < 4; j++)
			sum[i][j] = sum[i][j + 1];
		sum[i][4] = t;
	}
}

void setSum(int idx){
	for(int i = 0; i < 5; i++)
		sum[idx][i] = 0;
	int p = str[idx];
	for(int i = a[idx]; i <= b[idx]; i++){
		if(!mark[i])
			continue;
		sum[idx][p] += num[i].first;
		p++;
		if(p == 5)
			p = 0;
	}
}

int main(){
	char s[10];
	while(cin >> m){
		n = 0;
		memset(mark, false, sizeof mark);
		memset(sum, 0, sizeof sum);
		memset(str, 0, sizeof str);
		for(int i = 0; i < m; i++){
			scanf("%s", s);
			if(s[0] == 'a'){
				scanf("%d", &q[i][1]);
				q[i][0] = 0;
				num[n++] = P(q[i][1], n);
			}
			if(s[0] == 'd'){
				scanf("%d", &q[i][1]);
				q[i][0] = 1;
			}
			if(s[0] == 's')
				q[i][0] = 2;
		}
		sort(num, num + n);
		sz = (int)sqrt(5. * n);
		cnt = 0;
		int p = 0;
		while(p < n){
			a[cnt] = p;
			b[cnt] = min(n - 1, p + sz - 1);
			p = b[cnt++] + 1;
		}
		/*cout << sz << ' ' << cnt << endl;
		for(int i = 0; i < cnt; i++)
			cout << a[i] << ' ' << b[i] << endl;
		cout << "STR " << endl;*/
		for(int Q = 0; Q < m; Q++){
			//cout << "Q " << Q << endl;
			if(q[Q][0] == 0){
				int idx = bs(q[Q][1]);
				mark[idx] = true;
				setSum(idx / sz);
				inc(idx / sz + 1);
				//cout << idx << ' ' << idx / sz << endl;
			}
			if(q[Q][0] == 1){
				int idx = bs(q[Q][1]);
				mark[idx] = false;
				setSum(idx / sz);
				dec(idx / sz + 1);
				//cout << idx << ' ' << idx / sz << endl;
			}
			if(q[Q][0] == 2){
				int64 res = 0;
				for(int i = 0; i < cnt; i++)
					res += sum[i][2];
				cout << res << endl;
			}
			
			/*for(int i = 0; i < cnt; i++){
				for(int j = 0; j < 5; j++)
					cout << sum[i][j] << ' ';
				cout << endl;
			}*/
		}
	}
	return 0;
}
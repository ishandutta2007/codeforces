#include "bits/stdc++.h"
using namespace std;
const int N = 2e6 + 6;
char str[N];
int nxt[N];
int n , k;
bool check(int width){
	int cur = 1;
	int len = 0;
	int tot = 1;
	while(cur <= n){
		int siz = nxt[cur] - cur + 1;
		if(siz > width){
			return 0;
		}
		if(siz + len > width){
			len = 0;
			++tot;
			continue;
		}
		len += siz;
		cur = nxt[cur] + 1;
	}
	return tot <= k;
}
int main(){
	scanf("%d" , &k);
	n = 0;
	str[0] = ' ';
	while(~scanf("%s" , str + n + 1)){
		n += strlen(str + n + 1) + 1;
		str[n] = ' ';
	}
	str[n] = 0;
	--n;
	nxt[n] = n;
	for(int i = n - 1 ; i >= 1 ; --i){
		if(str[i] == '-' || str[i] == ' '){
			nxt[i] = i;
		}
		else{
			nxt[i] = nxt[i + 1];
		}
	}
	int l = 1;
	int r = n;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%d\n" , l);
}
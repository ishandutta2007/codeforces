#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using std::max;

const int MAXN =2e5+20, MAXS =450;

int read(){
	int x =0; char c =getchar(); bool f =0;
	while(c < '0' || c > '9') (c == '-') ? f =1, c =getchar() : c =getchar();
	while(c >= '0' && c <= '9') x =(x<<1)+(x<<3)+(48^c), c =getchar();
	return (f) ? -x : x;
}

int a[MAXN];
int D, cnt[MAXN], cnt_cnt[MAXN]/* \fad*/;

int pos_s[MAXN<<1];

int main(){
	int n =read(), S =sqrt(n), Max_Val =0;
	for(int i =0; i < n; ++i){
		a[i] =read(), ++cnt[a[i]];
		if(cnt[a[i]] > cnt[D])
			D =a[i];
		Max_Val =max(Max_Val, a[i]);
	}
	
	int ans =0;
	
	for(int k =1; k <= Max_Val; ++k)
		if(k != D && cnt[k] > S){
			int s =0;
			memset(pos_s, -1, sizeof(pos_s));
			pos_s[(int)2e5+ 0] =0;
			for(int i =0; i < n; ++i){
				if(a[i] == D)
					s +=1;
				else if(a[i] == k)
					s -=1;
				
				//  //
				//  //
				if(pos_s[(int)2e5+ s] == -1)
					pos_s[(int)2e5+ s] =i+1;
				
				if(pos_s[(int)2e5+ -(-s)] != -1)
					ans =max(ans, i-(pos_s[(int)2e5+ -(-s)]-1 +1)+1);
			}
		}
	
	for(int d_limit =1; d_limit <= S; ++d_limit){
		int max_cnt =0;
		memset(cnt, 0, sizeof(cnt));
	//	cnt_cnt[0] =cnt_different_val;/*<<- */
		//  //
		//  //
		for(int l =0, r =0; l < n; ++l){
			while(r < n && max(max_cnt, cnt[a[r]]+1) <= d_limit){
				--cnt_cnt[cnt[a[r]]], ++cnt[a[r]], ++cnt_cnt[cnt[a[r]]];
				max_cnt =max(max_cnt, cnt[a[r]]);
				++r;
			}
			
			if(cnt_cnt[max_cnt] >= 2)
				ans =max(ans, r-l);
			
			--cnt_cnt[cnt[a[l]]], --cnt[a[l]], ++cnt_cnt[cnt[a[l]]];
			if(cnt_cnt[max_cnt] == 0)
				--max_cnt;/* max_cnt */
		}
	}
	
	printf("%d", ans);
}
// test
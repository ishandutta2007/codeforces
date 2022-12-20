#include <stdio.h>
#include <string.h>
#include <vector>
#define MN 1000000
#define MK 5000
typedef long long LL;

int n,cntk[MK+5];
struct FAC{int num,cnt;};
typedef std::vector<FAC> NUM;
NUM num[MK+5];
LL ans;

void preprocess(){
	for(int i=1;i<=MK;i++){
		num[i] = num[i-1];
		int x=i,p=0;
		for(int j=2;j*j<=i;j++){
			if(x%j==0){
				for(;;p++){
					if(num[i][p].num == j){
						while(x%j==0){
							num[i][p].cnt++;
							x /= j;
						}
						break;
					}
				}
			}
		}
		if(x > 1){
			for(;p<num[i].size();p++){
				if(num[i][p].num == x){
					num[i][p].cnt++;
					x = 1;
				}
			}
			if(x > 1){
				num[i].push_back(FAC{x,1});
			}
		}
	}
}

int main(){
	preprocess();
	scanf("%d",&n);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		cntk[k]++;
	}
	for(int k=1;k<=MK;k++){
		int tot=0;
		for(int p=0;p<num[k].size();p++)
			tot += num[k][p].cnt;
		ans += 1ll * tot * cntk[k];
	}
	while(true){
		static int mxPrimeCnt[MK+5],mxPrime=1;
		memset(mxPrimeCnt,0,sizeof(mxPrimeCnt));
		for(int i=1;i<=MK;i++){
			if(num[i].size()==0) continue;
			mxPrimeCnt[num[i][num[i].size()-1].num] += cntk[i];
		}
		for(int i=1;i<=MK;i++){
			if(mxPrimeCnt[i] == 0) continue;
			if(mxPrimeCnt[i]>mxPrimeCnt[mxPrime]){
				mxPrime = i;
			}
		}
		if(mxPrime == 1) break;
		if(mxPrimeCnt[mxPrime]*2 <= n) break;
		ans = ans - mxPrimeCnt[mxPrime] + (n - mxPrimeCnt[mxPrime]);
		for(int i=1;i<=MK;i++){
			if(num[i].size()==0) continue;
			if(num[i][num[i].size()-1].num == mxPrime){
				num[i][num[i].size()-1].cnt--;
				if(num[i][num[i].size()-1].cnt == 0){
					num[i].pop_back();
				}
			}else{
				num[i].clear();
			}
		}
	}
	printf("%lld\n",ans);
}
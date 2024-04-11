#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b-1);i>=(a);i--)
#define fi first
#define se second
#define pb push_back 
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=(int)2e6+9;
char s[N];
int a[10][10][10],sum[10],ans[10][10];
void update(int &a,int b){
	if(a>b)a=b;
}
int main()
{
	rep(i,0,10)rep(j,0,10)rep(k,0,10)a[i][j][k]=100;
	rep(i,0,10){
		rep(j,0,10){
			rep(m,0,10){
				rep(n,0,10){
					if(m+n==0)continue;
					update(a[i][j][(m*i+n*j)%10],m+n);
				}
			} 
		}
	}
	scanf("%s",s);
	int len=strlen(s);
	rep(i,1,len){
		sum[(10+s[i]-s[i-1])%10]++;
	}
	rep(i,0,10){
		rep(j,0,10){
			rep(k,0,10){
				if(sum[k]&&a[i][j][k]==100){
					ans[i][j]=-1;
					break;
				}
				else {
					ans[i][j]+=sum[k]*(a[i][j][k]-1);
				}
			}
		}
	}
	rep(i,0,10){
		rep(j,0,10)printf("%d ",ans[i][j]);
		printf("\n");
	}
}
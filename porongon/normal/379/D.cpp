#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a,qwer=n;i<qwer;i++)
#define pb push_back
#define snd second
#define fst first
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int k;
ll x;
int n,m;
int s[128];int t[128];

void done(){
	fore(i,0,n)putchar('A'+s[i]);puts("");
	fore(i,0,m)putchar('A'+t[i]);puts("");
	exit(0);
}

ll f0[64],f1[64];
ll q[64][2][2];
int w[64][2]; // empieza,termina

bool can(int q, int n, int c0, int c1, int *s){
	s[0]=c0;
	s[n-1]=c1;
	if(n==1&&q!=0)return false;
	if(n==1&&q==0)return true;
	if(n==2){
		if(q==0){
			return c0!=0||c1!=2;
		}
		else {
			if(q>1)return false;
			return c0==0&&c1==2;
		}
	}
	fore(i,1,n-1){
		if(q==0)s[i]=1;
		else {
			if(s[i-1]==0){
				s[i]=2;q--;
			}
			else {
				s[i]=0;
			}
		}
	}
	if(s[n-2]==0&&s[n-1]==2)q--;
	return q==0;
}

void doit(int c0, int c1, int c2, int c3){
	f0[0]=1;f0[1]=0;
	f1[0]=0;f1[1]=1;
	w[0][0]=0;w[0][1]=0;
	w[1][0]=1;w[1][1]=1;
	fore(i,2,k){
		f0[i]=f0[i-2]+f0[i-1];
		f1[i]=f1[i-2]+f1[i-1];
		fore(i0,0,2)fore(j0,0,2)q[i][i0][j0]=q[i-2][i0][j0]+q[i-1][i0][j0];
		q[i][w[i-2][1]][w[i-1][0]]++;
		w[i][0]=w[i-2][0];
		w[i][1]=w[i-1][1];
	}
	ll qq=0;
	if(c1==0&&c0==2)qq+=q[k-1][0][0];
	if(c1==0&&c2==2)qq+=q[k-1][0][1];
	if(c3==0&&c0==2)qq+=q[k-1][1][0];
	if(c3==0&&c2==2)qq+=q[k-1][1][1];
	if(qq>x)return;
	//printf(" %lld\n",qq);
	fore(i,0,128)fore(j,0,128){
		if(qq+f0[k-1]*i+f1[k-1]*j!=x)continue;
		//if(i==0&&j==0)puts("hola");
		if(can(i,n,c0,c1,s)&&can(j,m,c2,c3,t))done();
	}
}


int main(){
	scanf("%d%lld%d%d",&k,&x,&n,&m);
	fore(c0,0,3)fore(c1,0,3){
		if(c0!=c1&&n==1)continue;
		fore(c2,0,3)fore(c3,0,3){
			if(c2!=c3&&m==1)continue;
			doit(c0,c1,c2,c3);
		}
	}
	puts("Happy new year!");
	return 0;
}
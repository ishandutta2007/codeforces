#include <iostream>

using namespace std;

const int MAXN=100111;
const int MAXK=111;
const int MOD=998244353;

int sr;
int sum(int a, int b){
	sr=a+b;
	if(sr>=MOD)	sr-=MOD;
	return sr;
}

int mul(int a, int b){
	return (int)((1LL*a*b)%(1LL*MOD));
}

int F[MAXN][MAXK];

int N, K, L;
int A[MAXN];
int _1[MAXN];
int Cnt[MAXN][MAXK];
int Pow[MAXN];

int C_(int l, int r){
	return _1[r]-_1[l-1];
}

int Way(int p, int k){
	if(A[p]<0)	return 1;
	return A[p]==k;
}

int Way(int l, int r, int k){
	if(Cnt[r][k]-Cnt[l-1][k]+C_(l, r)==(r-l+1))	return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> K >> L;
	
	Pow[0]=1;
	for(int i=1;i<=N;++i)	Pow[i]=mul(Pow[i-1], K);
	
	for(int i=1;i<=N;++i)	cin >> A[i];
	
	for(int i=1;i<=N;++i)	_1[i]=_1[i-1]+(A[i]<0);
	
	for(int i=1;i<=N;++i){
		for(int j=1;j<=K;++j)	Cnt[i][j]=Cnt[i-1][j];
		if(A[i]>0)	++Cnt[i][A[i]];
	}
	
	F[0][0]=1;
	for(int i=1;i<=N;++i){
		for(int k=1;k<=K;++k){
			F[i][k]=mul(F[i-1][0], Way(i, k));
			if(i==L)	F[i][k]=sum(F[i][k], MOD-Way(1, L, k));
			if(i>L){
				F[i][k]=sum(F[i][k], MOD-mul(F[i-L][0], Way(i-L+1, i, k)));
				F[i][k]=sum(F[i][k], mul(F[i-L][k], Way(i-L+1, i, k)));
			}
			//cout << i << " " << k << " " << F[i][k] << endl;
		}
		for(int k=1;k<=K;++k)	F[i][0]=sum(F[i][0], F[i][k]);
	}
	
	cout << F[N][0] << endl;
	
	return 0;
}


/*
#include <iostream>

using namespace std;

const int MAXN=100111;
const int MAXK=111;
const int MOD=998244353;

int sr;
int sum(int a, int b){
	sr=a+b;
	if(sr>=MOD)	sr-=MOD;
	return sr;
}

int mul(int a, int b){
	return (int)((1LL*a*b)%(1LL*MOD));
}

int N, K, L;
int A[MAXN];
int Cnt[MAXN][MAXK];
int _1[MAXN];
int Pow[MAXN];

int Kc(int l, int r){
	int ret=0;
	for(int i=1;i<=K;++i){
		if(Cnt[r][i]>Cnt[l-1][i])	++ret;
	}
	return ret;
}

int C_(int l, int r){
	return _1[r]-_1[l-1];
}

int Calc(int k){
	if(k>N)	return 0;
	int ret=0, temp;
	for(int l=1, r=l+k-1, c;r<=N;++l, ++r){
		c=Kc(l, r);
		if(c>1)	continue;
		if(c==1)	temp=1;
		else	temp=K;
		temp=mul(temp, mul(Pow[_1[l-1]], Pow[_1[N]-_1[r]]));
		ret=sum(ret, temp);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> K >> L;
	
	Pow[0]=1;
	for(int i=1;i<=N;++i)	Pow[i]=mul(Pow[i-1], K);
	
	for(int i=1;i<=N;++i)	cin >> A[i];
	
	for(int i=1;i<=N;++i)	_1[i]=_1[i-1]+(A[i]<0);
	
	for(int i=1;i<=N;++i){
		for(int j=1;j<=K;++j)	Cnt[i][j]=Cnt[i-1][j];
		if(A[i]>0)	++Cnt[i][A[i]];
	}
	
	int Ans=sum(Calc(L), MOD-Calc(L+1));
	Ans=sum(Pow[_1[N]], MOD-Ans);
	
	cout << Ans << endl;
	
	return 0;
}
*/

/*
2 2 2
1 -1

*/
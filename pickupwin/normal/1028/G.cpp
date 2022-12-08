#include <iostream>

using namespace std;

const long long M=10004205361450474LL;

long long A[10003];
int Ac;

int Ask(){
	cout << Ac << " ";
	for(int i=1;i<Ac;++i)	cout << A[i] << " ";
	cout << A[Ac] << endl;
	int ret;
	cin >> ret;
	return ret;
}

void Bf(long long l, long long r){
	long long len=(r-l+1LL);
	if(len<=10000LL){
		Ac=len;
		for(int i=1;i<=Ac;++i)	A[i]=l-1LL+(long long)(i);
		Ask();return;
	}
	long long d=len/10001LL;
	int le=(int)(len%10001LL);
	for(int i=1;i<=le;++i)	A[i]=d+1;
	for(int i=le+1;i<=Ac;++i)	A[i]=d;
	Ac=10000;
	A[0]=l-1LL;
	for(int i=1;i<=Ac;++i)
		A[i]+=A[i-1];
	A[Ac+1]=r+1LL;
	int ret=Ask();
	if(ret<0)	return;
	Bf(A[ret]+1LL, A[ret+1]-1LL);
}

long long F(int t, long long l){
	if(l>=M)	return M;
	if(t==0)	return l;
	int k=(int)(min(l, 10000LL));
	if(t==1)	return min(l+(long long)(k), M);
	for(int i=1;i<=k && l<M;++i, ++l)
		l=F(t-1, l);
	return min(F(t-1, l), M);
}

void Deal(int t, int k, long long l, long long r){
	//cout << t << " " << k << " " << l << " " << r << endl;
	if(k==10000)	{Bf(l, r);return;}
	Ac=k;
	A[0]=l-1LL;
	for(int i=1;i<=Ac;++i){
		A[i]=max(F(t-1, A[i-1]+1LL), A[i-1]+1LL);
		if(A[i]>r){
			Ac=i-1;
		}
	}
	A[Ac+1]=r+1LL;
	int ret=Ask();
	if(ret<0)	return;
	Deal(t-1, (int)(min(10000LL, A[ret]+1LL)), A[ret]+1LL, A[ret+1]-1LL);
}

int main(){
	
	Deal(5, 1, 1LL, M);
	
	return 0;
}
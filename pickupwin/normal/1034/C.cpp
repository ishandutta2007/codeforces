#include <iostream>

using namespace std;

const int MAXN=1000111;

long long gcd(long long a, long long b){
	return (b==0LL)?a:gcd(b, a%b);
}

int N;
long long A[MAXN], S[MAXN];
int Fa[MAXN];
int Cnt[MAXN];
int F[MAXN];

int Ans=0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> N;
	
	for(int i=1;i<=N;++i)
		cin >> A[i];
	
	for(int i=2;i<=N;++i)	cin >> Fa[i];
	
	for(int i=N;i>1;--i){
		S[i]+=A[i];
		S[Fa[i]]+=S[i];
	}
	S[1]+=A[1];
	
	long long k;
	for(int i=N;i>=1;--i){
		k=S[1]/gcd(S[i], S[1]);
		if(k>N)	continue;
		++Cnt[(int)(k)];
	}
	
	for(int i=N>>1;i;--i)
		for(int j=i+i;j<=N;j+=i)
			Cnt[j]+=Cnt[i];
	
	F[1]=1;
	for(int i=1;i<=N;++i){
		if(Cnt[i]==i){
			Ans+=F[i];
			for(int j=i+i;j<=N;j+=i){
				F[j]+=F[i];
			}
		}
	}
	
	cout << Ans << endl;
	
	return 0;
}